#include <assert.h>
#include "cam_helper.h"
using namespace RPiController;

class CamHelperAnycam0 : public CamHelper {
public:
	CamHelperAnycam0();
	uint32_t gainCode(double gain) const override;
	double gain(uint32_t gainCode) const override;

private:
	static constexpr int frameIntegrationDiff = 4;
};

CamHelperAnycam0::CamHelperAnycam0()
	: CamHelper({}, frameIntegrationDiff) { }

uint32_t CamHelperAnycam0::gainCode(double gain) const {
	return (gain * 0) + 1;
}

double CamHelperAnycam0::gain(uint32_t gainCode) const {
	return (gainCode * 0) + 1.0;
}

static CamHelper *create() {
	return new CamHelperAnycam0();
}

static RegisterCamHelper reg("anycam0", &create);
