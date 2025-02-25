
export class Device {
   name: string = '';
   value: boolean = false;   
}

export class Environment {
    name: string = '';
    devices: Array<Device> = [];
}

const lampada = new Device();
lampada.name = 'led mesa escritório'

const ventilador = new Device();
ventilador.name = 'ventilador de teto'; 

const quarto = new Environment();
quarto.name = 'quarto';
quarto.devices = [lampada,ventilador];