/*

Copyright (C) 2016 Julian L�hr
All rights reserved.

Filename:
	State.h

Abstract:
	Public managed class that represents the current state of a Wiimote Device including its settings.

*/
#pragma once

#include "Status.h"

typedef struct _WIIMOTE_STATE_IOCTL_DATA WIIMOTE_STATE_IOCTL_DATA;

namespace HIDWiimote
{
	namespace UserModeLib
	{
		public enum class DriverMode { PassThrough, Gamepad, IRMouse, DPadMouse, GamepadAndIRMouse };

		public ref class State
		{
		public:
			State(const WIIMOTE_STATE_IOCTL_DATA & StateData);

			property DriverMode Mode;
			property Status^ Status;
			property System::Boolean XAxisEnabled;
			property System::Boolean YAxisEnabled;
			property System::Boolean MouseButtonsSwitched;
			property System::Boolean TriggerAndShoulderSwitched;
			property System::Boolean TriggerSplit;

		private:
			void SetMode(WIIMOTE_DRIVER_MODE Mode);
		};
	}
}

