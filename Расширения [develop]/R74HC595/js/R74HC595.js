// R74HC595.js

(function(ext) {
    var device = null;
    
	ext.resetAll = function(){};
	
	ext.runArduino = function(){
		
	};

    function processData(bytes) {
        trace(bytes);
    }

    // Extension API interactions
    var potentialDevices = [];
    ext._deviceConnected = function(dev) {
        potentialDevices.push(dev);

        if (!device) {
            tryNextDevice();
        }
    }

    function tryNextDevice() {
        // If potentialDevices is empty, device will be undefined.
        // That will get us back here next time a device is connected.
        device = potentialDevices.shift();
        if (device) {
            device.open({ stopBits: 0, bitRate: 115200, ctsFlowControl: 0 }, deviceOpened);
        }
    }

    function deviceOpened(dev) {
        if (!dev) {
            // Opening the port failed.
            tryNextDevice();
            return;
        }
        device.set_receive_handler('R74HC595',function(data) {
            processData(data);
        });
    };

	
    ext._deviceRemoved = function(dev) {
        if(device != dev) return;
        device = null;
    };

    ext._shutdown = function() {
        if(device) device.close();
        device = null;
    };

    ext._getStatus = function() {
        if(!device) return {status: 1, msg: 'R74HC595 disconnected'};
        return {status: 2, msg: 'R74HC595 connected'};
    }

    var descriptor = {};
	ScratchExtensions.register('R74HC595', descriptor, ext, {type: 'serial'});
})({});