from os import access
from pyparsing import col
import serial
import serial.tools.list_ports
import matplotlib.pyplot as plt
from matplotlib import animation
from matplotlib.animation import FuncAnimation
import numpy as np
import csv
from datetime import datetime
import os.path

nbr_bille_tot = 0

myDatetime = datetime.now()

#initialisation des listes
ecart_type = []
Col = [1,2,3,4,5,6,7,8,9,10,11,12]
values =[0,0,0,0,0,0,0,0,0,0,0,0]
#Récupération des données via le port série
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

def animate(i):
        #Décodage des données et transformation en string
        global actualDonnee
        line1 = Data.readline()
        actualDonnee = line1.decode().strip().split()
    
        
        if len((actualDonnee)) == 12:
            #initialisation des nv chiffres
            longeur = len(actualDonnee)
            
            for i in range(longeur) :
                values[i] = int(actualDonnee[i])

            print('values', values)
            plt.gcf()
            plt.cla()
            plt.xlim(-40, 40)
            plt.ylim(0,50)
            plt.grid()
            plt.bar(Col, values)     

anim = FuncAnimation(plt.gcf(), animate, frames=5000, interval=200, repeat=False, cache_frame_data=False) # type: ignore

plt.show()

plt.close(plt.gcf())

Data.close()

print(values)


#créé une nouvell liste pour calculer l'ecar type
for n in range(len(values)) :
    for i in range((values[n])) :
        ecart_type.append((n+1))
#somme de toute les billes
for i in range(len(values)) :
    nbr_bille_tot = nbr_bille_tot+values[i]
#programme pour enrgister les résultats dans un csv
path = './experience/results.csv'
check_file = os.path.isfile(path)

print(check_file)


if not check_file:
    # Write the initial file
    with open('./experience/results.csv', 'w') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Date', 'Nbr billes',values[0], values[1], values[2],values[3],values[4],values[5],values[6],values[7],values[8],values[9],values[10],values[11],  'To keep'])
# Only append new values
if check_file:
    with open(path, 'a') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow([ myDatetime, nbr_bille_tot,values[0], values[1], values[2],values[3],values[4],values[5],values[6],values[7],values[8],values[9],values[10],values[11],  'To keep'])
        writer.writerow(ecart_type)