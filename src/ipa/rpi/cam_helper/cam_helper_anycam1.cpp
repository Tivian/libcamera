#include <assert.h>
#include "cam_helper.h"
using namespace RPiController;

class CamHelperAnycam1 : public CamHelper {
public:
	CamHelperAnycam1();
	uint32_t gainCode(double gain) const override;
	double gain(uint32_t gainCode) const override;

private:
	static constexpr int frameIntegrationDiff = 4;
};

CamHelperAnycam1::CamHelperAnycam1()
	: CamHelper({}, frameIntegrationDiff) { }

uint32_t CamHelperAnycam1::gainCode(double gain) const {
	return (gain * 0) + 1;
}

double CamHelperAnycam1::gain(uint32_t gainCode) const {
	return (gainCode * 0) + 1.0;
}

static CamHelper *create() {
	return new CamHelperAnycam1();
}

static RegisterCamHelper reg("anycam1", &create);
