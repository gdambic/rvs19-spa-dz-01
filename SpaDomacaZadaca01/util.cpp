#include "util.h"

namespace util {
	float map(float val, float valLow, float valHigh, float returnValLow, float returnValHigh) {
		float ratio = (val - valLow) / (valHigh - valLow);
		return ratio * (returnValHigh - returnValLow) + returnValLow;
	}
}
