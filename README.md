# Trabajo Practico N3 - Sistemas Embebidos
## Datos del alumno
    Lema, Adan Juan Angel.
    Ing. Electronica.
## Compilar
### make all
    Este es el comando para ejecutar el programa.
### make clean
    Este es el comando para borrar la carpeta que contiene los archivos ejecutados.
### make doc
    Genera la documentacion del proyecto.
### define DINAMIC
    Esta variable se encarga de decirle al compilador si utilizaremos memoria dinamica o estatica para crear la estructura alumno. Si optamos por memoria dinamica debemos borrar la parte de codigo "-D DINAMIC=0" del archivo makefile, esta se encuentra en la linea 22. En caso de que quieramos utilizar memoria estatica no debemos modificar el makefile.