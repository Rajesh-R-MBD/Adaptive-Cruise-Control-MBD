# <img width="4032" height="776" alt="image" src="https://github.com/user-attachments/assets/455fe70a-6568-4db3-86c4-0773fbe3594a" />


## Overview
Adaptive Cruise Control (ACC) is an advanced driver assistance system that automatically adjusts the vehicle's speed to maintain a safe distance from the vehicle ahead. Unlike conventional cruise control, ACC continuously monitors traffic conditions and modifies the vehicle's acceleration and deceleration accordingly.

This project focuses on the development of an Adaptive Cruise Control system using MATLAB/Simulink following Model-Based Development (MBD) processes. The system was designed, verified, and validated through requirement tracing, Signal Data Dictionary (SLDD) creation, Model Advisor checks, and automatic code generation using Embedded Coder.

## Objective
The primary objectives of this project are:

- Develop an Adaptive Cruise Control feature based on the provided requirement specifications.
- Implement the ACC logic using MATLAB Simulink and Stateflow.
- Follow Model-Based Development (MBD) methodologies.
- Create and configure Simulink Data Dictionary (SLDD).
- Perform Requirement Tagging and Traceability.
- Run Model Advisor checks for model compliance.
- Configure code generation settings.
- Generate production-ready C code using Embedded Coder.

## Adaptive Cruise Control Functionality

The ACC system performs the following operations:

- Maintains a constant vehicle speed when no leading vehicle is detected.
- Detects vehicles moving ahead using sensor inputs.
- Matches the speed of the lead vehicle when it enters the driving lane.
- Maintains a safe following distance based on the defined time gap.
- Resumes the set cruising speed when the lead vehicle leaves the lane.

## System Architecture

The model consists of three major subsystems:

### 1. Lead Vehicle Subsystem
**Inputs**
- CameraInput_LeadVehicle
- RadarInput_LeadVehicle

**Output**
- LeadVehicle_Speed

The lead vehicle speed is calculated by summing the camera and radar sensor inputs.

### 2. Drive Vehicle Subsystem
**Inputs**
- CameraInput_DriveVehicle
- RadarInput_DriveVehicle
- Acceleration_Mode (feedback signal)

**Outputs**
- DriveVehicle_Speed
- LeadVehicle_Detected

The subsystem determines the driver's vehicle speed and detects the presence of a lead vehicle using sensor information.

### 3. Adaptive Cruise Control Algorithm
The ACC controller is implemented using a Stateflow state machine.

#### Main States

##### ACC OFF Mode
- Default state.
- Acceleration_Mode = 0.
- Activated when CruiseSwitch = 0.

##### ACC STANDBY Mode
- Acceleration_Mode = 1.
- Activated when CruiseSwitch = 1.
- Waits for SetSwitch activation.

##### ACC ON Mode
- Activated when CruiseSwitch = 1 and SetSwitch = 1.
- Handles adaptive speed control operations.

## ACC ON Mode Sub-States

### LeadVehicle_Detected_Follow
- Default ACC ON state.
- Acceleration_Mode = 2.
- Follows the detected lead vehicle.

### LeadVehicle_Not_Detected
- Acceleration_Mode = 1.
- Maintains set speed when no vehicle is detected.

### LeadVehicle_Detected_Resume
- Acceleration_Mode = 3.
- Resumes normal cruising when conditions permit.

### LeadVehicle_Not_Detected_Resume
- Acceleration_Mode = 1.
- Returns to cruising speed after lead vehicle disappearance.

### LeadVehicle_Speed_LessThan_SetSpeed
- Acceleration_Mode = 4.
- Reduces speed to maintain safety distance.

### LeadVehicle_Speed_Equal_SetSpeed
- Acceleration_Mode = 5.
- Matches lead vehicle speed while maintaining the desired gap.

## Model-Based Development Activities

### Requirement Tagging and Traceability
Requirements were linked directly to the Simulink model elements using Requirement Management Interface, ensuring complete traceability.

### Simulink Data Dictionary (SLDD)
A dedicated SLDD file was created to manage:

- Input signals
- Output signals
- Calibration parameters
- Data types
- Signal storage classes

### Signal Resolution
All signals were resolved to Simulink objects to ensure consistency between the model and data dictionary.

### Model Advisor Checks
Model Advisor was executed to ensure compliance with MBD guidelines and best practices.

## Configuration Parameters

### Solver Configuration
- Fixed-Step Solver
- Sample Time: 0.01 sec

### Code Generation Settings
- System Target File: `ert.tlc`
- Embedded Coder enabled
- Support Floating Point Numbers enabled

### Storage Classes
| Signal Type | Storage Class |
|------------|--------------|
| Inputs | ImportedExtern |
| Outputs | ExportToFile |
| Local Signals | Localizable |
| Calibration Parameters | Const |

## Code Generation

Embedded Coder was used to automatically generate embedded C code from the Simulink model.

Generated files include:

- `ert_main.c`
- `ProjectACC.c`
- `ProjectACC.h`
- `ProjectACC_private.h`
- `ProjectACC_types.h`
- `Adaptive_Cruise_Control_Function.h`
- `Adaptive_Cruise_Control_Function_ROM.c`

The generated code can be integrated into embedded automotive platforms for real-time execution.

## Tools Used

- MATLAB
- Simulink
- Stateflow
- Simulink Data Dictionary (SLDD)
- Embedded Coder
- Model Advisor
- Requirement Management Interface

## Results

The Adaptive Cruise Control system was successfully designed and implemented according to the requirements specification. The project completed the entire MBD workflow including:

- Requirement Tagging & Traceability
- SLDD Creation
- Signal Resolution
- Model Advisor Verification
- Configuration Parameter Setup
- Embedded Code Generation

## Conclusion

This project demonstrates the implementation of an Adaptive Cruise Control system using MATLAB/Simulink and Stateflow while following industry-standard Model-Based Development practices. The developed model successfully controls vehicle speed, maintains safe vehicle spacing, and generates deployable C code suitable for embedded automotive applications.

## Author

**Rajesh R**

MATLAB | Simulink | Stateflow | Model-Based Development (MBD) | Embedded Systems
