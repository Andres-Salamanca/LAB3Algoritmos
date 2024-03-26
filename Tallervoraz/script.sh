#!/bin/bash

# Nombre de los scripts Python
script_random="random_activities.py"
# Nombre de los scripts de Greedy y Activity Selector DP
script_greedy="greedy.py"
script_activity_selector="dinamic.py"

# Crear directorio para guardar resultados
mkdir -p resultados

# Bucle sobre diferentes números de actividades y ranuras
for i in {1..100}; do
    num_activities=$((RANDOM % 100 + 1))
    num_slots=$((RANDOM % 100 + 1))

    # Generar actividades aleatorias
    random_file="resultados/activities_random_${num_activities}_${num_slots}.txt" 
    python3 $script_random $num_activities $num_slots > $random_file

    # Ejecutar el script de Greedy
    
    greedy_output="resultados/greedy_output_${num_activities}_${num_slots}.txt"
    python3 $script_greedy $random_file > $greedy_output

    # Ejecutar el script de Activity Selector DP
    
    activity_selector_output="resultados/activity_selector_output_${num_activities}_${num_slots}.txt"
    python3 $script_activity_selector $random_file > $activity_selector_output

    # Comparar las salidas de los scripts Greedy y Activity Selector DP
    echo "Comparando las salidas de los scripts Greedy y Activity Selector DP para $num_activities actividades y $num_slots slots..."
    if ! cmp -s $greedy_output $activity_selector_output; then
        echo "Las salidas para $num_activities actividades y $num_slots slots son diferentes. Terminando el programa."
        echo "Salida de Greedy ($greedy_output):"
        cat $greedy_output
        echo "Salida de Activity Selector DP ($activity_selector_output):"
        cat $activity_selector_output
        exit 1
    fi
    echo "Las salidas para $num_activities actividades y $num_slots slots son iguales."
    echo "Salida de Greedy :"
    cat $greedy_output
    echo "Salida de Activity Selector DP :"
    cat $activity_selector_output

    echo "-----------------------------------------------"
done

echo "Proceso completo."

