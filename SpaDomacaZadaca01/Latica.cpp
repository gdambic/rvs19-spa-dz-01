#include "Latica.h"
#include<cmath>

Latica::Latica()
{
   
	for (double i = 0; i < 10; i += 0.01) {
       Vertex linez[] =
        {
          Vertex(Vector2f(i*i,i*i)),
          Vertex(Vector2f((i+0.01)* (i + 0.01),(i + 0.01) * (i + 0.01)))

        };
      
	}
    
}

VertexArray Latica::dajLaticu()
{
    VertexArray linez(LinesStrip,10000000);
    int k = 0;
    for (double i = 0; i < 360; i += 0.01) {
        linez[k] = Vector2f(150+100*cos(i) ,150+25*sin(i));
       
        k++;
    }
   
    return linez;
}
