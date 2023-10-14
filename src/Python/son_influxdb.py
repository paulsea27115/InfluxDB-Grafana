import time
import requests, json
from influxdb import InfluxDBClient as influxdb

import serial

seri = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = None)

while(True):
    if seri.in_waiting != 0:
        content = seri.readline()[:-4].decode()
        cm = float(content)
    else:
        continue
    time.sleep(0.9)
    data = [{
        'measurement' : 'son',
        'tags' : {
            'hgcom' : '1234',
            },
        'fields' : {
            'son' : cm
            }
        }]
    client = None
    # print(cm)
    try:
        client = influxdb('localhost', 8086,'root','root','son')
    except Exception as e:
        print("Exception"+str(e))
    if client is not None:
        try:
            client.write_points(data)
        except Exception as e:
            print("Exception"+str(e))
        finally:
            client.close()
    print("running influxdb OK")



