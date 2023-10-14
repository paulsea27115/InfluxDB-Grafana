import serial

port = '/dev/ttyACM1'
brate = 9600
cmd = 'temp'

seri = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = None)
print(seri.name)

#seri.write(cmd.encode())

while 1:
    if seri.in_waiting != 0:
        content = seri.readline()
        res = content[:-2].decode()
        if "Dust" in res:
            print(res[14:])
