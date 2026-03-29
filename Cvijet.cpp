#include "Cvijet.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

static const float DAY_CYCLE = 30.0f;
static const float PI = 3.14159265f;

Cvijet::Cvijet(sf::RenderWindow& win)
    : window(win), totalTime(0.0f)
{
    winW = (float)win.getSize().x;
    winH = (float)win.getSize().y;

    W = 200.0f;
    H = 150.0f;
    canvas.create((unsigned)W, (unsigned)H);
    canvas.setSmooth(false);

    canvasSprite.setTexture(canvas.getTexture());
    canvasSprite.setScale(winW / W, winH / H);

    srand((unsigned)time(nullptr));

    for (int i = 0; i < 60; ++i)
        stars.push_back({ (float)(rand() % (int)W), (float)(rand() % (int)(H * 0.4f)),
                          0.5f + rand() % 50 / 100.0f, 1.5f + rand() % 300 / 100.0f,
                          rand() % 628 / 100.0f });

    for (int i = 0; i < 15; ++i)
        fireflies.push_back({ (float)(rand() % (int)W),
                               H * 0.5f + (float)(rand() % (int)(H * 0.35f)),
                               rand() % 628 / 100.0f, 0.8f + rand() % 200 / 100.0f });
}

float Cvijet::getDayFactor() const
{
    return (sin(totalTime * 2 * PI / DAY_CYCLE) + 1.0f) * 0.5f;
}

sf::Color Cvijet::lerp(sf::Color a, sf::Color b, float t) const
{
    t = max(0.0f, min(1.0f, t));
    return sf::Color((sf::Uint8)(a.r + (b.r - a.r) * t),
                     (sf::Uint8)(a.g + (b.g - a.g) * t),
                     (sf::Uint8)(a.b + (b.b - a.b) * t));
}

void Cvijet::draw()
{
    float dt = frameClock.restart().asSeconds();
    if (dt > 0.1f) dt = 0.1f;
    totalTime += dt;

    canvas.clear();

    drawSky();
    drawStars();
    drawMoon();
    drawSun();
    drawClouds();
    drawMountains();
    drawTrees();
    drawGround();
    drawFlowers();
    drawFireflies();

    canvas.display();
    window.draw(canvasSprite);
}

// ---- sky
void Cvijet::drawSky()
{
    float d = getDayFactor();
    sf::Color topN(12, 10, 35), topD(80, 140, 220);
    sf::Color botN(20, 15, 45), botD(220, 160, 100);

    sf::Color top = lerp(topN, topD, d);
    sf::Color bot = lerp(botN, botD, d);

    sf::VertexArray sky(sf::Quads, 4);
    sky[0] = sf::Vertex(sf::Vector2f(0, 0), top);
    sky[1] = sf::Vertex(sf::Vector2f(W, 0), top);
    sky[2] = sf::Vertex(sf::Vector2f(W, H), bot);
    sky[3] = sf::Vertex(sf::Vector2f(0, H), bot);
    canvas.draw(sky);
}

// ---- stars
void Cvijet::drawStars()
{
    float d = getDayFactor();
    if (d > 0.5f) return;
    float alpha = 1.0f - d / 0.5f;

    for (auto& s : stars)
    {
        float tw = 0.5f + 0.5f * sin(totalTime * s.speed + s.phase);
        sf::Uint8 a = (sf::Uint8)(255 * alpha * s.bright * tw);

        sf::RectangleShape px(sf::Vector2f(1, 1)); 
        px.setPosition(s.x, s.y);
        px.setFillColor(sf::Color(255, 245, 220, a));
        canvas.draw(px);
    }
}

// ---- moon
void Cvijet::drawMoon()
{
    float d = getDayFactor();
    if (d > 0.4f) return;
    float alpha = min(1.0f, (0.4f - d) / 0.2f);

    float angle = totalTime * 2 * PI / DAY_CYCLE + PI;
    float mx = W * 0.5f + cos(angle) * W * 0.3f;
    float my = H * 0.1f - sin(angle) * H * 0.06f;

    sf::CircleShape moon(6);
    moon.setOrigin(6, 6);
    moon.setFillColor(sf::Color(240, 230, 200, (sf::Uint8)(220 * alpha)));
    moon.setPosition(mx, my);
    canvas.draw(moon);

    sf::CircleShape shadow(5);
    shadow.setOrigin(5, 5);
    shadow.setFillColor(lerp(sf::Color(12, 10, 35), sf::Color(80, 140, 220), d));
    shadow.setPosition(mx + 3, my - 2);
    canvas.draw(shadow);
}

// ---- sun
void Cvijet::drawSun()
{
    float d = getDayFactor();
    if (d < 0.2f) return;
    float alpha = min(1.0f, (d - 0.2f) / 0.2f);

    float angle = totalTime * 2 * PI / DAY_CYCLE;
    float sx = W * 0.5f + cos(angle) * W * 0.35f;
    float sy = H * 0.08f - sin(angle) * H * 0.05f;

    float r = 5.0f + sin(totalTime * 3.0f);

    sf::CircleShape glow(r * 2);
    glow.setOrigin(r * 2, r * 2);
    glow.setFillColor(sf::Color(255, 200, 80, (sf::Uint8)(35 * alpha)));
    glow.setPosition(sx, sy);
    canvas.draw(glow);

    // body
    sf::CircleShape sun(r);
    sun.setOrigin(r, r);
    sun.setFillColor(sf::Color(255, 220, 100, (sf::Uint8)(255 * alpha)));
    sun.setPosition(sx, sy);
    canvas.draw(sun);
}

// ---- clouds
void Cvijet::drawClouds()
{
    float d = getDayFactor();
    sf::Uint8 a = (sf::Uint8)(160 * max(0.2f, d));

    float offsets[] = { 0, 50, 120, 170 };
    float ys[] = { 12, 22, 8, 28 };
    float speeds[] = { 6, 10, 4, 8 };

    for (int i = 0; i < 4; ++i)
    {
        float cx = fmod(offsets[i] + speeds[i] * totalTime, W + 30) - 15;
        sf::Color col(255, 250, 240, a);

        sf::RectangleShape r1(sf::Vector2f(12, 4));
        r1.setPosition(cx - 6, ys[i]);
        r1.setFillColor(col);
        canvas.draw(r1);

        sf::RectangleShape r2(sf::Vector2f(8, 3));
        r2.setPosition(cx - 4, ys[i] - 3);
        r2.setFillColor(col);
        canvas.draw(r2);
    }
}

// ---- mountains
void Cvijet::drawMountains()
{
    float d = getDayFactor();

    sf::Color farN(25, 20, 45), farD(120, 100, 130);
    sf::Color farC = lerp(farN, farD, d);

    for (int x = 0; x < (int)W; ++x)
    {
        float h = 25 + 15 * sin(x * 0.04f) + 8 * sin(x * 0.09f + 1);
        float top = H * 0.45f - h;
        sf::RectangleShape col(sf::Vector2f(1, H - top));
        col.setPosition((float)x, top);
        col.setFillColor(farC);
        canvas.draw(col);
    }

    sf::Color nearN(18, 28, 20), nearD(90, 115, 80);
    sf::Color nearC = lerp(nearN, nearD, d);

    for (int x = 0; x < (int)W; ++x)
    {
        float h = 18 + 12 * sin(x * 0.06f + 2) + 6 * sin(x * 0.13f);
        float top = H * 0.55f - h;
        sf::RectangleShape col(sf::Vector2f(1, H - top));
        col.setPosition((float)x, top);
        col.setFillColor(nearC);
        canvas.draw(col);
    }

    sf::Color snow = lerp(sf::Color(150, 145, 160), sf::Color(240, 235, 230), d);
    for (int x = 0; x < (int)W; ++x)
    {
        float h = 25 + 15 * sin(x * 0.04f) + 8 * sin(x * 0.09f + 1);
        if (h > 32)
        {
            float top = H * 0.45f - h;
            sf::RectangleShape px(sf::Vector2f(1, 3));
            px.setPosition((float)x, top);
            px.setFillColor(snow);
            canvas.draw(px);
        }
    }
}

// ---- trees
void Cvijet::drawTrees()
{
    float d = getDayFactor();
    sf::Color trunkN(20, 12, 8), trunkD(70, 45, 25);
    sf::Color trunk = lerp(trunkN, trunkD, d);

    float positions[] = { 10, 28, 45, 60, 78, 95, 115, 132, 148, 165, 180, 195 };
    float heights[]   = { 14, 18, 12, 16, 20, 14, 17,  13,  19,  15,  16,  11 };

    for (int i = 0; i < 12; ++i)
    {
        float tx = positions[i];
        float th = heights[i];
        float base = H * 0.72f;

        sf::RectangleShape t(sf::Vector2f(2, th * 0.4f));
        t.setPosition(tx, base - th * 0.4f + th);
        t.setFillColor(trunk);
        canvas.draw(t);

        sf::Color leafN(12, 30, 15), leafD(50, 110, 45);
        leafD.g = (sf::Uint8)min(255, leafD.g + i * 3);
        sf::Color leaf = lerp(leafN, leafD, d);

        for (int layer = 0; layer < 2; ++layer)
        {
            float lw = th * 0.5f * (1 - layer * 0.25f);
            float lh = th * 0.45f;
            float ly = base - layer * lh * 0.6f;

            for (int row = 0; row < (int)lh; ++row)
            {
                float frac = (float)row / lh;
                float rowW = lw * (1 - frac);
                sf::RectangleShape r(sf::Vector2f(rowW * 2, 1));
                r.setPosition(tx + 1 - rowW, ly - row);
                r.setFillColor(leaf);
                canvas.draw(r);
            }
        }
    }
}

// ---- ground
void Cvijet::drawGround()
{
    float d = getDayFactor();
    sf::Color gN(15, 32, 12), gD(65, 130, 50);
    sf::Color ground = lerp(gN, gD, d);

    sf::RectangleShape g(sf::Vector2f(W, H * 0.28f));
    g.setPosition(0, H * 0.72f);
    g.setFillColor(ground);
    canvas.draw(g);
    sf::Color dirtN(25, 18, 10), dirtD(110, 80, 50);
    sf::RectangleShape dirt(sf::Vector2f(W, H * 0.08f));
    dirt.setPosition(0, H * 0.92f);
    dirt.setFillColor(lerp(dirtN, dirtD, d));
    canvas.draw(dirt);
}

// ---- flowers
void Cvijet::drawFlowers()
{
    float d = getDayFactor();
    float baseY = H * 0.72f;

    struct F { float x; sf::Color col; float phase; };
    F flowers[] = {
        { W * 0.2f,  sf::Color(255, 100, 90),  0.0f },
        { W * 0.45f, sf::Color(255, 180, 70),  1.5f },
        { W * 0.65f, sf::Color(230, 90, 200),  3.0f },
        { W * 0.85f, sf::Color(255, 140, 100), 4.5f },
    };

    for (auto& f : flowers)
    {
        float sway = sin(totalTime * 1.5f + f.phase) * 2;
        float stemH = 12;

        sf::Color stemC = lerp(sf::Color(15, 35, 10), sf::Color(50, 120, 40), d);
        sf::RectangleShape stem(sf::Vector2f(1, stemH));
        stem.setPosition(f.x + sway * 0.3f, baseY - stemH);
        stem.setFillColor(stemC);
        canvas.draw(stem);

        float topX = f.x + sway * 0.5f;
        float topY = baseY - stemH;

        float pulse = 1.0f + 0.3f * sin(totalTime * 2.0f + f.phase);
        sf::Color pc = lerp(sf::Color(f.col.r / 3, f.col.g / 3, f.col.b / 3), f.col, d);
        int offsets[][2] = { {0,-2}, {0,2}, {-2,0}, {2,0} };

        for (auto& o : offsets)
        {
            sf::RectangleShape px(sf::Vector2f(2 * pulse, 2 * pulse));
            px.setPosition(topX + o[0] * pulse, topY + o[1] * pulse);
            px.setFillColor(pc);
            canvas.draw(px);
        }

        sf::RectangleShape center(sf::Vector2f(2, 2));
        center.setPosition(topX, topY);
        center.setFillColor(lerp(sf::Color(50, 40, 10), sf::Color(255, 210, 60), d));
        canvas.draw(center);
    }
}

// ---- fireflies
void Cvijet::drawFireflies()
{
    float d = getDayFactor();
    if (d > 0.4f) return;
    float alpha = 1.0f - d / 0.4f;

    for (auto& f : fireflies)
    {
        float glow = 0.5f + 0.5f * sin(totalTime * f.speed + f.phase);
        float ox = sin(totalTime * f.speed * 0.5f + f.phase) * 8;
        float oy = cos(totalTime * f.speed * 0.7f + f.phase) * 5;

        sf::Uint8 a = (sf::Uint8)(220 * alpha * glow);

        sf::RectangleShape px(sf::Vector2f(1, 1));
        px.setPosition(f.x + ox, f.y + oy);
        px.setFillColor(sf::Color(220, 255, 120, a));
        canvas.draw(px);
    }
}
