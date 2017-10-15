// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/logging/log.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/lm/lm.h"

namespace Service {
namespace LM {

void InstallInterfaces(SM::ServiceManager& service_manager) {
    std::make_shared<LM>()->InstallAsService(service_manager);
}

/**
 * LM::Initialize service function
 *  Inputs:
 *      0: 0x00000000
 *  Outputs:
 *      0: ResultCode
 */
void LM::Initialize(Kernel::HLERequestContext& ctx) {
    IPC::RequestBuilder rb{ctx, 1};
    rb.Push(RESULT_SUCCESS);
    LOG_WARNING(Service_SM, "(STUBBED) called");
}

LM::LM() : ServiceFramework("lm") {
    static const FunctionInfo functions[] = {
        {0x00000000, &LM::Initialize, "Initialize"},
    };
    RegisterHandlers(functions);
}

LM::~LM() = default;

} // namespace LM
} // namespace Service
