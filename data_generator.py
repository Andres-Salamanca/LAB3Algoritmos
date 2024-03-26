import random

# Función para generar una línea con una cantidad específica de elementos
def generar_linea(num_elementos):
    return ",".join(str(random.randint(1, 100)) for _ in range(num_elementos))

# Ruta del archivo de salida
archivo_salida = "entradas.txt"

# Cantidad inicial de elementos por línea
num_elementos = 10

# Abrir archivo de salida en modo escritura
with open(archivo_salida, "w") as file:
    # Generar líneas con incremento de 10 elementos hasta llegar a 1000
    while num_elementos <= 1000:
        # Generar línea con la cantidad actual de elementos
        linea = generar_linea(num_elementos)
        # Escribir la línea en el archivo
        file.write(linea + "\n")
        # Incrementar la cantidad de elementos para la próxima línea
        num_elementos += 10
