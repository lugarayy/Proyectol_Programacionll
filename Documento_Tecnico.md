Universidad Nacional - Curso: Programación II - Profesor: Jonathan Morales Murillo
------------------------------------
------------------------------------
Diseño de clases
------------------------------------
El diseño general de las clases está organizado en los siguientes módulos principales 
(y archivos asociados en el repo):

- Dominio/Equipos
  - `Equipo` (abstracta) — `Equipo.h` / `Equipo.cpp`
  - `EquipoCritico` — `EquipoCritico.h` / `EquipoCritico.cpp`
  - `EquipoEstandar` — `EquipoEstandar.h` / `EquipoEstandar.cpp`
  - `DefinirEquipo` — `DefinirEquipo.h` / `DefinirEquipo.cpp` 

- Incidencias (patrón Decorator)
  - `Incidencia` (abstracta) — `IncidenciaBase.h` / `IncidenciaBase.cpp`
  - `DecoradorIncidencia` (abstracto) — `DecoradorIncidencia.h` / `DecoradorIncidencia.cpp`
  - `IncidenciaSeveridadAlta`, `IncidenciaSeveridadMedia`, `IncidenciaSeveridadBaja` — archivos correspondientes

- Motor de simulación
  - `Simulador` — `Simulador.h` / `Simulador.cpp`
  - `LectorArchivos` — `LectorArchivos.h` / `LectorArchivos.cpp`
  - `Ordenamiento` — `Ordenamiento.h` / `Ordenamiento.cpp` (implementa MergeSort/QuickSort propio)
  - `BusquedaBinaria` — `BusquedaBinaria.h` / `BusquedaBinaria.cpp`
  - `EleccionPrioridad` — `EleccionPrioridad.h` / `EleccionPrioridad.cpp`
  - `GeneradorIncidencias` — `GeneradorIncidencias.h` / `GeneradorIncidencias.cpp`
  - `GeneradorReportes` — `GeneradorReportes.h` / `GeneradorReportes.cpp`
  - `CalcularRiesgo` — `CalcularRiesgo.h` / `CalcularRiesgo.cpp`

- Excepciones personalizadas
  - `InvalidoException` (base)
  - `ArchivoInvalidoException`, `FormatoInvalidoException`, `OperacionInconsistenteException`, `MenorACeroException`
------------------------------------
Patrónes de diseño aplicados
------------------------------------
- Decorator: aplicado en el subsystem de Incidencias. `DecoradorIncidencia` envuelve una `Incidencia` (o `IncidenciaBase`) para añadir severidad y 
- comportamiento adicional sin modificar la clase base. Esto permite componer incidencias con características adicionales.

- Strategy: la selección de equipos a mantener (módulo `EleccionPrioridad`) se puede considerar una estrategia intercambiable; actualmente se implementa una 
- estrategia por prioridad (fórmula obligatoria) y la infraestructura permite cambiar la política de selección si se desea (inyección de dependencia de una clase que 
- implemente la política).

------------------------------------
Relaciones entre clases
------------------------------------
Herencia:
- EquipoCritico y EquipoEstandar heredan de Equipo (abstracta).
  Equipo define el comportamiento común: getPrioridad(), degradar(),
  aplicaMantenimiento(), getTipo().

- IncidenciaSeveridadAlta, IncidenciaSeveridadMedia, IncidenciaSeveridadBaja
  heredan de DecoradorIncidencia, que a su vez hereda de Incidencia (abstracta).

- ArchivoInvalidoException, FormatoInvalidoException,
  OperacionInconsistenteException y MenorACeroException heredan de
  InvalidoException, que hereda de runtime_error.

Composición:
- Equipo contiene un vector<Incidencia*>, es dueño de las incidencias
  y las elimina en su destructor.

Upcasting:
- LectorArchivos crea objetos EquipoCritico* y EquipoEstandar* pero los
  almacena en vector<Equipo*>. Todo el sistema trabaja polimórficamente
  con Equipo*.

Downcasting:
- En Simulador, al mostrar los equipos atendidos se usa dynamic_cast<EquipoCritico*>
  para acceder a generarAlerta(), comportamiento exclusivo de EquipoCritico.
  Si el cast falla retorna nullptr y no se ejecuta la alerta.

Dependencia mutua:
- Equipo e Incidencia se referencian mutuamente. Resuelta con forward
  declaration en ambos headers y los includes completos en los .cpp.

------------------------------------
Fórmula de prioridad (RF4)
------------------------------------
La prioridad diaria de cada equipo se calcula obligatoriamente como:

prioridad = (criticidad * 0.5) + (incidencias_activas * 0.3) + (tiempo_inactivo * 0.2)

Este valor se almacena en cada objeto `Equipo` y se recalcula cada día durante la simulación. Si
dos equipos tienen la misma prioridad, se utiliza `criticidad` como criterio de desempate.

------------------------------------
Algoritmo propio de ordenamiento
------------------------------------
El algoritmo de ordenamiento recae en `Ordenamiento.cpp`.

Que funciona con un QuickSort implementado sobre `vector<Equipo*>`. Justificación:
La implementación incluye:
- Orden descendente por prioridad (mayor prioridad primero).
- Para comparaciones iguales, se utiliza `criticidad` o `id` como criterio secundario para determinarlo.

------------------------------------
Búsqueda optimizada
------------------------------------
Se implementó la búsqueda binaria en `BusquedaBinaria.cpp` para localizar equipos por `id`
para ingresar sus incidencias leídas desde LectorArchivo desde el archivo equipos.txt.


Manejo de excepciones personalizadas
---------------------------------------
Se definieron excepciones específicas para los errores esperados:
- `ArchivoInvalidoException` — archivo no encontrado o inaccesible.
- `FormatoInvalidoException` — línea inválida en archivos de entrada.
- `OperacionInconsistenteException` — cuando la simulación detecta estados imposibles.
- `MenorACeroException` — valores numéricos negativos donde no tienen sentido.

Estas clases heredan de `InvalidoException` y permiten capturar errores con mensajes significativos en `main.cpp`.

------------------------------------------
Dependencia mutua y forward declaration
------------------------------------------
Existe dependencia entre `Equipo` y `Incidencia` (un `Equipo` contiene o referencia incidencias y las incidencias contienen el id del equipo).

- `Incidencia.h` declara `class Equipo;` cuando necesita referenciar `Equipo*` u `id`, y la inclusión del header completo (`#include "Equipo.h"`) se deja en el `.cpp` cuando es necesario.

------------------------------------
Persistencia y reportes (E9, E10)
------------------------------------
La generación de reportes queda en `GeneradorReportes`. Se generan archivos de texto por día en la carpeta `Simulacion/` ya presente en `cmake-build-debug/Simulacion/` 
(Si no existe el mismo código la crea y si ya existe, igualmente la borra con todo dentro y la vuelve a crear) del repo. Los reportes contienen:
- Día
- Equipos atendidos
- Prioridades calculadas
- Backlog pendiente
- Riesgo global (vía `CalcularRiesgo`)


---

Fecha: 28-04-2026

Lucia Garay García y Jose Pablo Sánchez Ramírez
— Proyecto Programación II - 2026

