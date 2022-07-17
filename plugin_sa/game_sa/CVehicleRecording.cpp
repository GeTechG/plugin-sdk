#include "CVehicleRecording.h"
#include "CStreaming.h"

// 0x45A060
bool CVehicleRecording::HasRecordingFileBeenLoaded(INT32 rrrNumber) {
    return plugin::CallAndReturn<bool, 0x45A060, INT32>(rrrNumber);
}

// 0x45A8F0
void CVehicleRecording::Load(RwStream* stream, INT32 resourceId, INT32 totalSize) {
    return plugin::Call<0x45A8F0, RwStream*, INT32, INT32>(stream, resourceId, totalSize);
}

// 0x45A0F0
void CVehicleRecording::SmoothRecording(INT32 resourceId) {
    assert(0);
}

// 0x459F80
INT32 CVehicleRecording::RegisterRecordingFile(const char* name) {
    return plugin::CallAndReturn<INT32, 0x459F80, const char*>(name);

    auto recordId = 850;
    if (sscanf(name, "carrec%d", &recordId) == 0) {
        sscanf(name, "CARREC%d", &recordId);
    }

    StreamingArray[NumPlayBackFiles].m_nNumber = recordId;
    StreamingArray[NumPlayBackFiles].m_pData = nullptr;
    return NumPlayBackFiles++;
}

void CVehicleRecording::RemoveRecordingFile(INT32) {
    assert(0);
}


void CVehicleRecording::RequestRecordingFile(INT32) {
    assert(0);
}

// 0x45A980
void CVehicleRecording::StartPlaybackRecordedCar(CVehicle* vehicle, INT32 pathNumber, bool useCarAI, bool bLooped) {
    plugin::Call<0x45A980, CVehicle*, INT32, bool, bool>(vehicle, pathNumber, useCarAI, bLooped);
}

// 0x45A280
void CVehicleRecording::StopPlaybackRecordedCar(CVehicle* vehicle) {
    plugin::Call<0x45A280, CVehicle*>(vehicle);
}

// 0x459740
void CVehicleRecording::PausePlaybackRecordedCar(CVehicle* vehicle) {
    assert(0);
}

// 0x459850
void CVehicleRecording::UnpausePlaybackRecordedCar(CVehicle* vehicle) {
    assert(0);
}

// 0x459660
void CVehicleRecording::SetPlaybackSpeed(CVehicle* vehicle, float speed) {
    plugin::Call<0x459660, CVehicle*, float>(vehicle, speed);
}

// 0x45A610
void CVehicleRecording::SaveOrRetrieveDataForThisFrame() {
    plugin::Call<0x45A610>();
}

// 0x4594C0
bool CVehicleRecording::IsPlaybackGoingOnForCar(CVehicle* vehicle) {
    return plugin::CallAndReturn<bool, 0x4594C0, CVehicle*>(vehicle);
}

// 0x4595A0
bool CVehicleRecording::IsPlaybackPausedForCar(CVehicle* vehicle) {
    return plugin::CallAndReturn<bool, 0x4595A0, CVehicle*>(vehicle);
}
