#pragma once


#include "CPathFind.h"
#include "CVehicle.h"
#include "ССonstants.h"
#include <array>

class CVehicleStateEachFrame {
public:
    float   m_fTime;
    INT16   m_sVelocityX;
    INT16   m_sVelocityY;
    INT16   m_sVelocityZ;
    UINT8   m_bRightX;
    UINT8   m_bRightY;
    UINT8   m_bRightZ;
    UINT8   m_bTopX;
    UINT8   m_bTopY;
    UINT8   m_bTopZ;
    UINT8   m_bSteeringAngle;
    UINT8   m_bGasPedalPower;
    UINT8   m_bBreakPedalPower;
    UINT8   m_bHandbrakeUsed;
    CVector m_vecPosn;
};

class CPath {
public:
    INT32                   m_nNumber;
    CVehicleStateEachFrame* m_pData;
    INT32                   m_nSize;
    INT8                    m_nRefCount;
};

VALIDATE_SIZE(CVehicleStateEachFrame, 0x20);
VALIDATE_SIZE(CPath, 0x10);

struct RwStream;

constexpr auto TOTAL_VEHICLE_RECORDS = 16;

class CVehicleRecording {
public:
    static inline INT32& NumPlayBackFiles = *(INT32*)0x97F630;
    static inline std::array<CPath, TOTAL_RRR_MODEL_IDS>& StreamingArray = *(std::array<CPath, TOTAL_RRR_MODEL_IDS>*)0x97D880;
    static inline std::array<CVehicle*, TOTAL_VEHICLE_RECORDS> pVehicleForPlayback = *(std::array<CVehicle*, TOTAL_VEHICLE_RECORDS>*)0x97D840;
    static inline std::array<CVehicleStateEachFrame*, TOTAL_VEHICLE_RECORDS> pPlaybackBuffer = *(std::array<CVehicleStateEachFrame*, TOTAL_VEHICLE_RECORDS>*)0x97D800;
    static inline std::array<INT32, TOTAL_VEHICLE_RECORDS> PlaybackIndex = *(std::array<INT32, TOTAL_VEHICLE_RECORDS>*)0x97D7C0;
    static inline std::array<INT32, TOTAL_VEHICLE_RECORDS> PlaybackBufferSize = *(std::array<INT32, TOTAL_VEHICLE_RECORDS>*)0x97D780;
    static inline std::array<float, TOTAL_VEHICLE_RECORDS> PlaybackRunningTime = *(std::array<float, TOTAL_VEHICLE_RECORDS>*)0x97D740;
    static inline std::array<float, TOTAL_VEHICLE_RECORDS> PlaybackSpeed = *(std::array<float, TOTAL_VEHICLE_RECORDS>*)0x97D700;
    static inline std::array<bool, TOTAL_VEHICLE_RECORDS> bPlaybackGoingOn = *(std::array<bool, TOTAL_VEHICLE_RECORDS>*)0x97D6F0;
    static inline std::array<bool, TOTAL_VEHICLE_RECORDS> bPlaybackLooped = *(std::array<bool, TOTAL_VEHICLE_RECORDS>*)0x97D6E0;
    static inline std::array<bool, TOTAL_VEHICLE_RECORDS> bPlaybackPaused = *(std::array<bool, TOTAL_VEHICLE_RECORDS>*)0x97D6D0;
    static inline std::array<bool, TOTAL_VEHICLE_RECORDS> bUseCarAI = *(std::array<bool, TOTAL_VEHICLE_RECORDS>*)0x97D6C0;
    // static inline int32 PlayBackStreamingIndex = 0x97D670;
    // DisplayMode

public:

    /*
     * ChangeCarPlaybackToUseAI(CVehicle*)
     * FindIndexWithFileNameNumber(int32)
     * InterpolateInfoForCar(CVehicle*, CVehicleStateEachFrame*, float)
     */

    static bool HasRecordingFileBeenLoaded(INT32 rrrNumber);
    static void Load(RwStream* stream, INT32 resourceId, INT32 totalSize);
    static void SmoothRecording(INT32 resourceId);

    static INT32 RegisterRecordingFile(const char* name);
    static void RemoveRecordingFile(INT32);
    static void RequestRecordingFile(INT32);

    static void SetPlaybackSpeed(CVehicle* vehicle, float speed);

    /*
     * RemoveAllRecordingsThatArentUsed()
     * RestoreInfoForCar(CVehicle*, CVehicleStateEachFrame*, bool)
     * RestoreInfoForMatrix(CMatrix&, CVehicleStateEachFrame*)
     */
    static void SaveOrRetrieveDataForThisFrame();
    /*
     * SetRecordingToPointClosestToCoors(int32, CVector)
     * SkipForwardInRecording(CVehicle*, float)
     * SkipToEndAndStopPlaybackRecordedCar(CVehicle*)
     * StopPlaybackWithIndex(int32)
     */
    static void StartPlaybackRecordedCar(CVehicle* vehicle, INT32 pathNumber, bool useCarAI, bool bLooped);
    static void StopPlaybackRecordedCar(CVehicle* vehicle);
    static void PausePlaybackRecordedCar(CVehicle* vehicle);
    static void UnpausePlaybackRecordedCar(CVehicle* vehicle);

    static bool IsPlaybackGoingOnForCar(CVehicle* vehicle);
    static bool IsPlaybackPausedForCar(CVehicle* vehicle);
};
