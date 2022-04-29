
"use strict";

let ExtendedState = require('./ExtendedState.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let ESCTelemetry = require('./ESCTelemetry.js');
let ESCStatusItem = require('./ESCStatusItem.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let GPSINPUT = require('./GPSINPUT.js');
let ActuatorControl = require('./ActuatorControl.js');
let LogData = require('./LogData.js');
let Tunnel = require('./Tunnel.js');
let Mavlink = require('./Mavlink.js');
let LandingTarget = require('./LandingTarget.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let PositionTarget = require('./PositionTarget.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let StatusText = require('./StatusText.js');
let PlayTuneV2 = require('./PlayTuneV2.js');
let ESCStatus = require('./ESCStatus.js');
let HilSensor = require('./HilSensor.js');
let WaypointList = require('./WaypointList.js');
let LogEntry = require('./LogEntry.js');
let GPSRAW = require('./GPSRAW.js');
let Param = require('./Param.js');
let HilControls = require('./HilControls.js');
let RadioStatus = require('./RadioStatus.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let VehicleInfo = require('./VehicleInfo.js');
let EstimatorStatus = require('./EstimatorStatus.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let MountControl = require('./MountControl.js');
let RCOut = require('./RCOut.js');
let TerrainReport = require('./TerrainReport.js');
let FileEntry = require('./FileEntry.js');
let Waypoint = require('./Waypoint.js');
let GPSRTK = require('./GPSRTK.js');
let Thrust = require('./Thrust.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let Altitude = require('./Altitude.js');
let CommandCode = require('./CommandCode.js');
let ESCInfo = require('./ESCInfo.js');
let RTCM = require('./RTCM.js');
let ESCTelemetryItem = require('./ESCTelemetryItem.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let HomePosition = require('./HomePosition.js');
let CameraImageCaptured = require('./CameraImageCaptured.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let BatteryStatus = require('./BatteryStatus.js');
let WaypointReached = require('./WaypointReached.js');
let DebugValue = require('./DebugValue.js');
let ManualControl = require('./ManualControl.js');
let State = require('./State.js');
let MagnetometerReporter = require('./MagnetometerReporter.js');
let NavControllerOutput = require('./NavControllerOutput.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let RCIn = require('./RCIn.js');
let HilGPS = require('./HilGPS.js');
let ParamValue = require('./ParamValue.js');
let RTKBaseline = require('./RTKBaseline.js');
let ESCInfoItem = require('./ESCInfoItem.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let Trajectory = require('./Trajectory.js');
let Vibration = require('./Vibration.js');
let VFR_HUD = require('./VFR_HUD.js');

module.exports = {
  ExtendedState: ExtendedState,
  AttitudeTarget: AttitudeTarget,
  ESCTelemetry: ESCTelemetry,
  ESCStatusItem: ESCStatusItem,
  HilStateQuaternion: HilStateQuaternion,
  GPSINPUT: GPSINPUT,
  ActuatorControl: ActuatorControl,
  LogData: LogData,
  Tunnel: Tunnel,
  Mavlink: Mavlink,
  LandingTarget: LandingTarget,
  OpticalFlowRad: OpticalFlowRad,
  PositionTarget: PositionTarget,
  OverrideRCIn: OverrideRCIn,
  StatusText: StatusText,
  PlayTuneV2: PlayTuneV2,
  ESCStatus: ESCStatus,
  HilSensor: HilSensor,
  WaypointList: WaypointList,
  LogEntry: LogEntry,
  GPSRAW: GPSRAW,
  Param: Param,
  HilControls: HilControls,
  RadioStatus: RadioStatus,
  WheelOdomStamped: WheelOdomStamped,
  VehicleInfo: VehicleInfo,
  EstimatorStatus: EstimatorStatus,
  TimesyncStatus: TimesyncStatus,
  MountControl: MountControl,
  RCOut: RCOut,
  TerrainReport: TerrainReport,
  FileEntry: FileEntry,
  Waypoint: Waypoint,
  GPSRTK: GPSRTK,
  Thrust: Thrust,
  GlobalPositionTarget: GlobalPositionTarget,
  CamIMUStamp: CamIMUStamp,
  Altitude: Altitude,
  CommandCode: CommandCode,
  ESCInfo: ESCInfo,
  RTCM: RTCM,
  ESCTelemetryItem: ESCTelemetryItem,
  CompanionProcessStatus: CompanionProcessStatus,
  HomePosition: HomePosition,
  CameraImageCaptured: CameraImageCaptured,
  ADSBVehicle: ADSBVehicle,
  BatteryStatus: BatteryStatus,
  WaypointReached: WaypointReached,
  DebugValue: DebugValue,
  ManualControl: ManualControl,
  State: State,
  MagnetometerReporter: MagnetometerReporter,
  NavControllerOutput: NavControllerOutput,
  HilActuatorControls: HilActuatorControls,
  RCIn: RCIn,
  HilGPS: HilGPS,
  ParamValue: ParamValue,
  RTKBaseline: RTKBaseline,
  ESCInfoItem: ESCInfoItem,
  OnboardComputerStatus: OnboardComputerStatus,
  Trajectory: Trajectory,
  Vibration: Vibration,
  VFR_HUD: VFR_HUD,
};
