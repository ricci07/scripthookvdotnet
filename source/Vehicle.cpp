#include "Ped.hpp"
#include "Vehicle.hpp"
#include "Native.hpp"

namespace GTA
{
	Vehicle::Vehicle(int id) : Entity(id)
	{
	}

	Vehicle ^Vehicle::Any::get()
	{
		return gcnew Vehicle(0);
	}

	bool Vehicle::HasRoof::get()
	{
		return Native::Function::Call<bool>(Native::Hash::DOES_VEHICLE_HAVE_ROOF, this->ID);
	}
	int Vehicle::PassengerSeats::get()
	{
		return Native::Function::Call<int>(Native::Hash::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS, this->ID);
	}
	System::String ^Vehicle::DisplayName::get()
	{
		return Native::Function::Call<System::String ^>(Native::Hash::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL, this->Model.Hash);
	}
	System::String ^Vehicle::NumberPlate::get()
	{
		return Native::Function::Call<System::String ^>(Native::Hash::GET_VEHICLE_NUMBER_PLATE_TEXT, this->ID);
	}
	void Vehicle::NumberPlate::set(System::String ^value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_NUMBER_PLATE_TEXT, this->ID, value);
	}
	bool Vehicle::IsConvertible::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_A_CONVERTIBLE, this->ID, 0);
	}
	bool Vehicle::IsStolen::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_STOLEN, this->ID);
	}
	void Vehicle::IsStolen::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_IS_STOLEN, this->ID, value);
	}
	bool Vehicle::IsDriveable::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_DRIVEABLE, this->ID, 0);
	}
	void Vehicle::IsDriveable::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_UNDRIVEABLE, this->ID, !value);
	}
	bool Vehicle::IsOnAllWheels::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_ON_ALL_WHEELS, this->ID);
	}
	float Vehicle::Speed::get()
	{
		return Native::Function::Call<float>(Native::Hash::GET_ENTITY_SPEED, this->ID);
	}
	void Vehicle::Speed::set(float value)
	{
		if (this->Model.IsTrain)
		{
			Native::Function::Call(Native::Hash::SET_TRAIN_SPEED, this->ID, value);
			Native::Function::Call(Native::Hash::SET_TRAIN_CRUISE_SPEED, this->ID, value);
		}
		else
		{
			Native::Function::Call(Native::Hash::SET_VEHICLE_FORWARD_SPEED, this->ID, value);
		}
	}
	float Vehicle::DirtLevel::get()
	{
		return Native::Function::Call<float>(Native::Hash::GET_VEHICLE_DIRT_LEVEL, this->ID);
	}
	void Vehicle::DirtLevel::set(float value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_DIRT_LEVEL, this->ID, value);
	}
	VehicleRoofState Vehicle::RoofState::get()
	{
		return static_cast<VehicleRoofState>(Native::Function::Call<int>(Native::Hash::GET_CONVERTIBLE_ROOF_STATE, this->ID));
	}
	void Vehicle::RoofState::set(VehicleRoofState value)
	{
		switch (value)
		{
		case VehicleRoofState::Closed:
		case VehicleRoofState::Closing:
			Native::Function::Call(Native::Hash::RAISE_CONVERTIBLE_ROOF, this->ID, 0);
			break;
		case VehicleRoofState::Opened:
		case VehicleRoofState::Opening:
			Native::Function::Call(Native::Hash::LOWER_CONVERTIBLE_ROOF, this->ID, 0);
			break;
		}
	}
	float Vehicle::EngineHealth::get()
	{
		return Native::Function::Call<float>(Native::Hash::GET_VEHICLE_ENGINE_HEALTH, this->ID);
	}
	void Vehicle::EngineHealth::set(float value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_ENGINE_HEALTH, this->ID, value);
	}
	float Vehicle::PetrolTankHealth::get()
	{
		return Native::Function::Call<float>(Native::Hash::GET_VEHICLE_PETROL_TANK_HEALTH, this->ID);
	}
	void Vehicle::PetrolTankHealth::set(float value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_PETROL_TANK_HEALTH, this->ID, value);
	}
	bool Vehicle::SirenActive::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_SIREN_ON, this->ID);
	}
	void Vehicle::SirenActive::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_SIREN, this->ID, value);
	}
	VehicleColor Vehicle::PrimaryColor::get()
	{
		int color1, color2;
		Native::Function::Call(Native::Hash::GET_VEHICLE_COLOURS, this->ID, &color1, &color2);

		return static_cast<VehicleColor>(color1);
	}
	void Vehicle::PrimaryColor::set(VehicleColor value)
	{
		int color1, color2;
		Native::Function::Call(Native::Hash::GET_VEHICLE_COLOURS, this->ID, &color1, &color2);
		Native::Function::Call(Native::Hash::SET_VEHICLE_COLOURS, this->ID, static_cast<int>(value), color2);
	}
	VehicleColor Vehicle::SecondaryColor::get()
	{
		int color1, color2;
		Native::Function::Call(Native::Hash::GET_VEHICLE_COLOURS, this->ID, &color1, &color2);

		return static_cast<VehicleColor>(color2);
	}
	void Vehicle::SecondaryColor::set(VehicleColor value)
	{
		int color1, color2;
		Native::Function::Call(Native::Hash::GET_VEHICLE_COLOURS, this->ID, &color1, &color2);
		Native::Function::Call(Native::Hash::SET_VEHICLE_COLOURS, this->ID, color1, static_cast<int>(value));
	}
	VehicleWheelType Vehicle::WheelType::get()
	{
		return static_cast<VehicleWheelType>(Native::Function::Call<int>(Native::Hash::GET_VEHICLE_WHEEL_TYPE, this->ID));
	}
	void Vehicle::WheelType::set(VehicleWheelType wheelType)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_WHEEL_TYPE, this->ID, static_cast<int>(wheelType));
	}
	VehicleWindowTint Vehicle::WindowTint::get()
	{
		return static_cast<VehicleWindowTint>(Native::Function::Call<int>(Native::Hash::GET_VEHICLE_WINDOW_TINT, this->ID));
	}
	void Vehicle::WindowTint::set(VehicleWindowTint windowTint)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_WINDOW_TINT, this->ID, static_cast<int>(windowTint));
	}
	bool Vehicle::IsPrimaryColorCustom::get()
	{
		return Native::Function::Call<bool>(Native::Hash::_DOES_VEHICLE_HAVE_SECONDARY_COLOUR, this->ID);
	}
	bool Vehicle::IsSecondaryColorCustom::get()
	{
		return Native::Function::Call<bool>(Native::Hash::_0x910A32E7AAD2656C, this->ID);
	}

	void Vehicle::IsWanted::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_IS_WANTED, this->ID, value);
	}
	void Vehicle::EngineRunning::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_ENGINE_ON, this->ID, value, true);
	}
	void Vehicle::LightsOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_LIGHTS, this->ID, value ? 3 : 4);
	}
	void Vehicle::BrakeLightsOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_BRAKE_LIGHTS, this->ID, value);
	}
	void Vehicle::LeftIndicatorLightOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_INDICATOR_LIGHTS, this->ID, true, value);
	}
	void Vehicle::RightIndicatorLightOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_INDICATOR_LIGHTS, this->ID, false, value);
	}
	bool Vehicle::TaxiLightOn::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_TAXI_LIGHT_ON, this->ID);
	}
	void Vehicle::TaxiLightOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_TAXI_LIGHTS, this->ID, value);
	}
	bool Vehicle::SearchLightOn::get()
	{
		return Native::Function::Call<bool>(Native::Hash::IS_VEHICLE_SEARCHLIGHT_ON, this->ID);
	}
	void Vehicle::SearchLightOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_SEARCHLIGHT, this->ID, value, 0);
	}
	void Vehicle::InteriorLightOn::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_INTERIORLIGHT, this->ID, value);
	}
	void Vehicle::NeedsToBeHotwired::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_NEEDS_TO_BE_HOTWIRED, this->ID, value);
	}
	void Vehicle::CanTiresBurst::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_TYRES_CAN_BURST, this->ID, value);
	}
	void Vehicle::CanBeVisiblyDamaged::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED, this->ID, value);
	}
	void Vehicle::PreviouslyOwnedByPlayer::set(bool value)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER, this->ID, value);
	}
	void Vehicle::CustomPrimaryColor::set(System::Drawing::Color color)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR, this->ID, color.R, color.G, color.B);
	}
	void Vehicle::CustomSecondaryColor::set(System::Drawing::Color color)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR, this->ID, color.R, color.G, color.B);
	}

	int Vehicle::GetMod(VehicleMod modType)
	{
		return Native::Function::Call<int>(Native::Hash::GET_VEHICLE_MOD, this->ID, static_cast<int>(modType));
	}
	void Vehicle::SetMod(VehicleMod modType, int modIndex, bool variations)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_MOD, this->ID, static_cast<int>(modType), modIndex, variations);
	}
	void Vehicle::ToggleMod(VehicleToggleMod toggleMod, bool toggle)
	{
		Native::Function::Call(Native::Hash::TOGGLE_VEHICLE_MOD, this->ID, static_cast<int>(toggleMod), toggle);
	}
	bool Vehicle::IsToggleModOn(VehicleToggleMod toggleMod)
	{
		return Native::Function::Call<bool>(Native::Hash::IS_TOGGLE_MOD_ON, this->ID, static_cast<int>(toggleMod));
	}
	void Vehicle::ClearCustomPrimaryColor()
	{
		Native::Function::Call(Native::Hash::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR, this->ID);
	}
	void Vehicle::ClearCustomSecondaryColor()
	{
		Native::Function::Call(Native::Hash::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR, this->ID);
	}
	Ped ^Vehicle::GetPedOnSeat(VehicleSeat seat)
	{
		const int handle = Native::Function::Call<int>(Native::Hash::GET_PED_IN_VEHICLE_SEAT, this->ID, static_cast<int>(seat));

		if (handle == 0)
		{
			return nullptr;
		}

		return gcnew Ped(handle);
	}

	void Vehicle::Repair()
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_FIXED, this->ID);
	}
	void Vehicle::Explode()
	{
		Native::Function::Call(Native::Hash::EXPLODE_VEHICLE, this->ID, true, false);
	}
	bool Vehicle::SetOnGround()
	{
		return Native::Function::Call<bool>(Native::Hash::SET_VEHICLE_ON_GROUND_PROPERLY, this->ID);
	}
	void Vehicle::OpenDoor(VehicleDoor door, bool loose, bool instantly)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_DOOR_OPEN, this->ID, static_cast<int>(door), loose, instantly);
	}
	void Vehicle::CloseDoor(VehicleDoor door, bool instantly)
	{
		Native::Function::Call(Native::Hash::SET_VEHICLE_DOOR_SHUT, this->ID, static_cast<int>(door), instantly);
	}
	void Vehicle::FixWindow(VehicleWindow window)
	{
		Native::Function::Call(Native::Hash::FIX_VEHICLE_WINDOW, this->ID, static_cast<int>(window));
	}
	void Vehicle::SmashWindow(VehicleWindow window)
	{
		Native::Function::Call(Native::Hash::SMASH_VEHICLE_WINDOW, this->ID, static_cast<int>(window));
	}
	void Vehicle::RollUpWindow(VehicleWindow window)
	{
		Native::Function::Call(Native::Hash::ROLL_UP_WINDOW, this->ID, static_cast<int>(window));
	}
	void Vehicle::RollDownWindow(VehicleWindow window)
	{
		Native::Function::Call(Native::Hash::ROLL_DOWN_WINDOW, this->ID, static_cast<int>(window));
	}
	void Vehicle::RollDownWindows()
	{
		Native::Function::Call(Native::Hash::ROLL_DOWN_WINDOWS, this->ID);
	}
	void Vehicle::RemoveWindow(VehicleWindow window)
	{
		Native::Function::Call(Native::Hash::REMOVE_VEHICLE_WINDOW, this->ID, static_cast<int>(window));
	}
}