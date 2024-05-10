from os import access
from pyparsing import col
import serial
import serial.tools.list_ports
import matplotlib.pyplot as plt
from matplotlib import animation
from matplotlib.animation import FuncAnimation
import time
import random
import numpy
import itertools


L_tempsMesure = []
L_temps = []
acquisition = 30.0

L_infoA = []
L_infoB = []
L_infoC = []

Col = [1,2,3]
values =[0,0,0]
values2 = []

t_range = 10

def anim(i):
    
    global actualDonnee
    line1 = Data.readline()
    actualDonnee = line1.decode().strip().split()
    tempsmes = time.time()
    L_tempsMesure.append(tempsmes)
    tempsreel = tempsmes - L_tempsMesure[0]
    
    if len((actualDonnee[2])) != 0:
        
        Numero = int(actualDonnee[2])
        Bins = 0
        print(actualDonnee)
        tempsmes = time.time()
        L_tempsMesure.append(tempsmes)
        tempsreel = float(tempsmes - L_tempsMesure[0])
        L_temps.append(tempsreel)
            
        while tempsreel <= acquisition:
            
            tempsmes = time.time()
            tempsreel = float(tempsmes - L_tempsMesure[0])

            for l in (actualDonnee[0]) :
                if l == "A":
                    Bins = 0
                elif l == "B":
                    Bins = 1
                elif l == "C" :
                    Bins = 2
            values[Bins] = Numero
            #print('values', values)
            
            plt.cla()
            
            return plt.bar([1,2,3], values)

            

            
def get_ports(lettre="",chiffre=""):
    ports = list(serial.tools.list_ports.comports())
    for i in ports :
        if 'Arduino' in i.description:
            Data_co = serial.Serial(i.device,9600)
    print(Data_co.is_open)
    print(Data_co.name)
    return Data_co

Data = get_ports()

fig=plt.figure()
plt.xlim(0, 20)
plt.ylim(0,50)
plt.grid()

animations = FuncAnimation(plt.gcf(), anim,frames=200, interval=20, repeat=False, cache_frame_data=False) # type: ignore

plt.show()

plt.close(plt.gcf())

Data.close()

print(Col)
print(values)