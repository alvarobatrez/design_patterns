# Implementor: Define la interfaz para los dispositivos
class Device:

    def power_on(self):
        pass

    def power_off(self):
        pass

    def set_volume(self, volume):
        pass

    def get_volume(self):
        pass

# Concrete Implementor: Implementación concreta para TV
class TV(Device):

    def __init__(self):
        self.volume = 10

    def power_on(self):
        print('TV is now ON')

    def power_off(self):
        print('TV is now OFF')

    def set_volume(self, volume):
        self.volume = volume
        print(f'TV volume set to {self.volume}')

    def get_volume(self):
        return self.volume
    
# Concrete Implemetor: Implementación concreta para Radio
class Radio(Device):

    def __init__(self):
        self.volume = 5

    def power_on(self):
        print('Radio is now ON')

    def power_off(self):
        print('Radio is now OFF')

    def set_volume(self, volume):
        self.volume = volume
        print(f'Radio volume set to {self.volume}')

    def get_volume(self):
        return self.volume
    
# Abstraction: Control remoto genérico
class RemoteControl:

    def __init__(self, device):
        self.device = device
        self.is_on = False

    def toggle_power(self):
        if self.is_on:
            self.device.power_off()
        else:
            self.device.power_on()
        
        self.is_on = not self.is_on

    def volume_up(self):
        volume = self.device.get_volume()
        self.device.set_volume(volume + 1)

    def volume_down(self):
        volume = self.device.get_volume()
        self.device.set_volume(volume -1)

# Refined Abstraction: Control remoto avanzado con función mute
class AdvancedRemoteControl(RemoteControl):

    def mute(self):
        self.device.set_volume(0)
        print("Device is muted")

# Cliente
if __name__ == '__main__':
    # Crear un dispositivo TV y un control remoto básico
    tv = TV()
    basic_remote = RemoteControl(tv)

    basic_remote.toggle_power()
    basic_remote.volume_up()
    basic_remote.volume_down()
    basic_remote.toggle_power()

    print()

    radio = Radio()
    advanced_remote = AdvancedRemoteControl(radio)

    advanced_remote.toggle_power()
    advanced_remote.volume_up()
    advanced_remote.mute()
    advanced_remote.toggle_power()