
export class Device {
<<<<<<< HEAD
    id: string = '';
    name: string = '';
    state: boolean = false;    
    icon: string = 'devices';
    pin: number = 0;
=======
    name: string = '';
    state: boolean = false;    
    icon: string = 'devices'
>>>>>>> b73a17c362d0686f89922b7e35c3f47cdf4daafe
}

export class Environment {
    id: string = '';
    name: string = '';
    devices: Array<Device> = [];
}

<<<<<<< HEAD
export class ResponseSys {
    id: string = '';
}

export class ResponseItem<T> {
    fields: T|null;
    sys: ResponseSys = new ResponseSys();

    constructor(initialValue:T) {
        this.fields = initialValue;
    }
}

export class ApiResponse<T> {
    items: Array<ResponseItem<T>> = [];    
}


=======
>>>>>>> b73a17c362d0686f89922b7e35c3f47cdf4daafe
