## Test1

### Task1

**Условие:** </br>
Простой неориентированный граф задан матрицей смежности, выведите его представление в виде списка ребер. </br>
**Формат входных данных:** </br>
Входной файл содержит число N (1 <= N <= 100) — число вершин в графе, и затем N строк по N чисел,
каждое из которых равно 0 или 1 — его матрицу смежности. </br>
**Формат выходных данных:** </br>
Выведите в выходной файл список ребер заданного графа. Ребра можно выводить в произвольном порядке.

### Task2

**Условие:** </br>
В этой задаче требуется проверить, что граф является связным, то есть что из любой
вершины можно по рёбрам этого графа попасть в любую другую. </br>
**Формат входных данных:** </br>
В первой строке входного файла заданы числа N и M через пробел — количество вершин
и рёбер в графе, соответственно (1 <= N <= 100, 0 <= M <= 10000).
Следующие M строк содержат по два числа u_i и v_i через пробел (1 <= u_i, v_i <= N);
каждая такая строка означает, что в графе существует ребро между вершинами 𝑢_i и v_i. </br>
**Формат выходных данных:** </br>
Выведите “YES”, если граф является связным, и “NO” в противном случае.

### Task3

**Условие:** </br>
Дано прямоугольное поле W * H. Некоторые клетки проходимы, через некоторые ходить
нельзя. Из клетки можно ходить в соседние по ребру (слева, справа, сверху, снизу).
Нужно из клетки (𝑥1, 𝑦1) найти любой (не обязательно кратчайший, даже не обязательно
простой) путь в клетку (𝑥2, 𝑦2). </br>
**Формат входных данных:** </br>
На первой строке 𝑊, 𝐻, 𝑥1, 𝑦1, 𝑥2, 𝑦2 (1 <= 𝑥1, 𝑥2 <= 𝑊 <= 1000, 1 <= 𝑦1, 𝑦2 <= 𝐻 <= 1000).
Далее 𝐻 строк, в каждой из которых по 𝑊 символов. Символ “.” означает, что клетка проходима,
а символ “*” означает, что по ней ходить нельзя.
Клетки (𝑥1, 𝑦1) и (𝑥2, 𝑦2) не совпадают и обе проходимы. </br>
**Формат выходных данных:** </br>
Если пути не существует, выведите NO.
Иначе выведите YES и последовательность клеток (𝑥𝑖, 𝑦𝑖), в которой первая совпадает с
клеткой (𝑥1, 𝑦1), а последняя с клеткой (𝑥2, 𝑦2).

### Task4

**Условие** </br>
Дан ориентированный невзвешенный граф. Необходимо его топологически отсортировать. </br>
**Формат входных данных** </br>
В первой строке входного файла даны два натуральных числа 𝑁 и 𝑀
(1 <= 𝑁 <= 100000, 𝑀 <= 100000) — количество вершин и рёбер в графе соответственно. Далее в 𝑀 строках перечислены рёбра графа. Каждое ребро задаётся парой чисел —
номерами начальной и конечной вершин соответственно. </br>
**Формат выходных данных** </br>
Вывести любую топологическую сортировку графа в виде последовательности номеров
вершин. Если граф невозможно топологически отсортировать, вывести -1.

### Task5

**Условие** </br>
Дан ориентированный невзвешенный граф. Необходимо определить есть ли в нём циклы,
и если есть, то вывести любой из них.  </br>
**Формат входных данных** </br>
В первой строке входного файла находятся два натуральных числа 𝑁 и 𝑀
(1 <= 𝑁 <= 100000, 𝑀 <= 100000) — количество вершин и рёбер в графе соответственно. Далее
в 𝑀 строках перечислены рёбра графа. Каждое ребро задаётся парой чисел — номерами
начальной и конечной вершин соответственно. </br>
**Формат выходных данных** </br>
Если в графе нет цикла, то вывести «NO», иначе — «YES» и затем перечислить все вершины в порядке обхода цикла.

### Task6

**Условие** </br>
Дан связный граф. Требуется найти сумму расстояний между всеми парами вершин. </br>
**Формат входных данных** </br>
Первая строка входного файла содержит два натуральных числа 𝑛 и 𝑚 — количество
вершин и ребер графа соответственно (1 <= 𝑛 <= 1000, 0 <= 𝑚 <= 10000).
Следующие 𝑚 строк содержат описание ребер по одному на строке. Ребро номер 𝑖 описывается двумя натуральными числами 𝑏𝑖, 𝑒𝑖 — номерами концов ребра (1 <= 𝑏𝑖, 𝑒𝑖 <= 𝑛).
Гарантируется, что граф связен. </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать одно натуральное число — сумму попарных расстояний между вершинами.

## Test2

### Task1

**Условие:** </br>
Полный ориентированный взвешенный граф задан матрицей смежности. Постройте матрицу кратчайших путей между его вершинами.
Гарантируется, что в графе нет циклов от рицательного веса. </br>
**Формат входных данных:** </br>
В первой строке вводится единственное число 𝑁 (1 <= 𝑁 <= 100) — количество вершин
графа. В следующих 𝑁 строках по 𝑁 чисел задается матрица смежности графа (𝑗-ое число
в 𝑖-ой строке — вес ребра из вершины 𝑖 в вершину 𝑗). Все числа по модулю не превышают 100.
На главной диагонали матрицы — всегда нули. </br>
**Формат выходных данных:** </br>
Выведите 𝑁 строк по 𝑁 чисел — матрицу расстояний между парами вершин,
где 𝑗-ое число в 𝑖-ой строке равно весу кратчайшего пути из вершины 𝑖 в 𝑗.

### Task2

**Условие:** </br>
Дан взвешенный граф. Требуется найти вес минимального пути между двумя вершинами. </br>
**Формат входных данных:** </br>
Первая строка входного файла содержит два натуральных числа 𝑛 и 𝑚 — количество
вершин и ребер графа соответственно. Вторая строка входного файла содержит натуральные
числа 𝑠 и 𝑡 — номера вершин, длину пути между которыми требуется найти (1 <= 𝑠, 𝑡 <= 𝑛, 𝑠 != 𝑡).
Следующие 𝑚 строк содержат описание ребер по одному на строке.
Ребро номер 𝑖 описывается тремя натуральными числами 𝑏𝑖, 𝑒𝑖 и 𝑤𝑖 — номера концов ребра и его вес соответственно
(1 <= 𝑏𝑖, 𝑒𝑖 <= 𝑛, 0 <= 𝑤𝑖 <= 100). 𝑛 <= 100000, 𝑚 <= 200000. </br>
**Формат выходных данных:** </br>
Первая строка выходного файла должна содержать одно натуральное число — вес минимального пути между вершинами 𝑠 и 𝑡.
Если путь из 𝑠 в 𝑡 не существует, выведите -1.

### Task3

**Условие:** </br>
Дан взвешенный ориентированный граф и вершина 𝑠 в нем.
Требуется для каждой вершины 𝑢 найти длину кратчайшего пути из 𝑠 в 𝑢. </br>
**Формат входных данных:** </br>
Первая строка входного файла содержит 𝑛, 𝑚 и 𝑠 — количество вершин, ребер и номер
выделенной вершины соответственно (2 <= 𝑛 <= 2000, 1 <= 𝑚 <= 5000).
Следующие 𝑚 строк содержат описание ребер. Каждое ребро задается стартовой вершиной, конечной вершиной и весом ребра.
Вес каждого ребра — целое число, не превосходящее 10^15 по модулю. В графе могут быть кратные ребра и петли. </br>
**Формат выходных данных:** </br>
Выведите 𝑛 строк — для каждой вершины 𝑢 выведите длину кратчайшего пути из 𝑠 в 𝑢,
‘*’ если не существует путь из 𝑠 в 𝑢 и ‘-’ если не существует кратчайший путь из 𝑠 в 𝑢.

### Task4

**Условие** </br>
Дан связный взвешенный неориентированный граф.
Рассмотрим пару вершин, расстояние между которыми максимально среди всех пар вершин. 
Расстояние между ними называется диаметром графа. Эксцентриситетом вершины v
называется максимальное расстояние от вершины v до других вершин графа. Радиусом графа
называется наименьший из эксцентриситетов вершин. Найдите диаметр и радиус графа. </br>
**Формат входных данных** </br>
В первой строке входного файла единственное число: 𝑁 (1 <= 𝑁 <= 100) — количество
вершин графа. В следующих 𝑁 строках по 𝑁 чисел — матрица смежности графа, где -1
означает отсутствие ребра между вершинами, а любое неотрицательное число — присутствие
ребра данного веса. На главной диагонали матрицы всегда нули; веса рёбер не превышают 1000. </br>
**Формат выходных данных** </br>
В выходной файл выведите два числа — диаметр и радиус графа.

### Task5

**Условие** </br>
Дан ориентированный граф. Определите, есть ли в нем цикл отрицательного веса, и если да, то выведите его.  </br>
**Формат входных данных** </br>
Во входном файле в первой строке число 𝑁 (1 <= 𝑁 <= 100) — количество вершин графа.
В следующих 𝑁 строках находится по 𝑁 чисел — матрица смежности графа. Все веса ребер
не превышают по модулю 10000. Если ребра нет, то соответствующее число равно 100000. </br>
**Формат выходных данных** </br>
В первой строке выходного файла выведите «YES», если цикл существует или «NO» в
противном случае. При его наличии выведите во второй строке количество вершин в искомом
цикле и в третьей строке — вершины входящие в этот цикл в порядке обхода.

## Test3

### Task1

**Условие** </br>
Дан неориентированный граф. Требуется найти все мосты в нем. </br>
**Формат входных данных** </br>
Первая строка входного файла содержит два натуральных числа 𝑛 и 𝑚 — количество
вершин и ребер графа соответственно (𝑛 <= 20 000, 𝑚 <= 200 000).
Следующие 𝑚 строк содержат описание ребер по одному на строке. Ребро номер 𝑖 описывается двумя натуральными числами 𝑏𝑖, 𝑒𝑖 — 
номерами концов ребра (1 <= 𝑏𝑖, 𝑒𝑖 <= 𝑛). </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать одно натуральное число 𝑏 — количество мостов в заданном графе. 
На следующей строке выведите 𝑏 целых чисел — номера ребер, которые являются мостами, в возрастающем порядке. 
Ребра нумеруются с единицы в том порядке, в котором они заданы во входном файле.

### Task2

**Условие** </br>
Дан неориентированный граф. Требуется найти все точки сочленения в нем. </br>
**Формат входных данных** </br>
Первая строка входного файла содержит два натуральных числа 𝑛 и 𝑚 — количество
вершин и ребер графа соответственно (𝑛 <= 20 000, 𝑚 <= 200 000).
Следующие 𝑚 строк содержат описание ребер по одному на строке. Ребро номер 𝑖 опи-
сывается двумя натуральными числами 𝑏𝑖, 𝑒𝑖 — номерами концов ребра (1 <= 𝑏𝑖, 𝑒𝑖 <= 𝑛). </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать одно натуральное число 𝑏 — количе-
ство точек сочленения в заданном графе. На следующей строке выведите 𝑏 целых чисел —
номера вершин, которые являются точками сочленения, в возрастающем порядке.

### Task3

**Условие** </br>
Требуется найти в связном графе остовное дерево минимального веса. </br>
**Формат входных данных** </br>
Первая строка входного файла содержит два натуральных числа 𝑛 и 𝑚 — количество вер-
шин и ребер графа соответственно. Следующие 𝑚 строк содержат описание ребер по одному
на строке. Ребро номер 𝑖 описывается тремя натуральными числами 𝑏𝑖, 𝑒𝑖 и 𝑤𝑖 — номера кон-
цов ребра и его вес соответственно (1 <= 𝑏𝑖, 𝑒𝑖 <= 𝑛, 0 <= 𝑤𝑖 <= 100 000). 𝑛 <= 20 000, 𝑚 <= 100 000.
Граф является связным. </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать одно натуральное число — вес мини-
мального остовного дерева.

### Task4

**Условие** </br>
В Байтландии есть целых 𝑛 городов, но нет ни одной дороги. Король решил исправить эту
ситуацию и соединить некоторые города дорогами так, чтобы по этим дорогам можно было
бы добраться от любого города до любого другого. Когда строительство будет завершено,
Король планирует отпраздновать День Объединения. К сожалению, казна Байтландии почти
пуста, поэтому Король требует сэкономить деньги, минимизировав суммарную длину всех
построенных дорог. </br>
**Формат входных данных** </br>
Первая строка входного файла содержит натуральное число 𝑛 (1 <= 𝑛 <= 5 000) — количество городов в Байтландии. 
Каждая из следующих 𝑛 строк содержит два целых числа 𝑥𝑖, 𝑦𝑖
— координаты 𝑖-го города (−10 000 <= 𝑥𝑖, 𝑦𝑖 <= 10 000). Никакие два города не расположены в
одной точке. </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать минимальную суммарную длину дорог. Выведите число с точностью не менее 10−3

### Task5

**Условие** </br>
Петя нарисовал на бумаге 𝑛 кружков и соединил некоторые пары кружков линиями.
После этого он раскрасил каждый кружок в один из трех цветов — красный, синий или
зеленый.
Теперь Петя хочет изменить их раскраску. А именно — он хочет перекрасить каждый
кружок в некоторый другой цвет так, чтобы никакие два кружка одного цвета не были
соединены линией. При этом он хочет обязательно перекрасить каждый кружок, а перекрашивать кружок в тот же цвет, 
в который он был раскрашен исходно, не разрешается.
Помогите Пете решить, в какие цвета следует перекрасить кружки, чтобы выполнялось
указанное условие. </br>
**Формат входных данных** </br>
Первая строка содержит два целых числа 𝑛 и 𝑚 — количество кружков и количество
линий, которые нарисовал Петя, соответственно (1 <= 𝑛 <= 1 000, 0 <= 𝑚 <= 20 000).
Следующая строка содержит 𝑛 символов из множества {‘R’, ‘G’, ‘B’} — 𝑖-й из этих символов означает цвет, 
в который раскрашен 𝑖-й кружок (‘R’ — красный, ‘G’ — зеленый, ‘B’ — синий).
Следующие 𝑚 строк содержат по два целых числа — пары кружков, соединенных отрезками. </br>
**Формат выходных данных** </br>
Выведите в выходной файл одну строку, состоящую из 𝑛 символов из множества
{‘R’, ‘G’, ‘B’} — цвета кружков после перекраски. Если решений несколько, выведите любое.
Если решения не существует, выведите в выходной файл слово “Impossible”.

## Test4

### Task1

**Условие** </br>
Дано подвешенное дерево с корнем в 1-й вершине и 𝑀 запросов вида “найти у двух вершин
наименьшего общего предка”. </br>
**Формат входных данных** </br>
В первой строке файла записано одно число 𝑁 — количество вершин. В следующих 𝑁 − 1
строках записаны числа. Число 𝑥 на строке 2 <= 𝑖 <= 𝑁 означает, что 𝑥 — отец вершин 𝑖.
(𝑥 < 𝑖). На следующей строке число 𝑀 . Следующие 𝑀 строк содержат запросы вида (𝑥, 𝑦)
— найти наименьшего предка вершин 𝑥 и 𝑦 Ограничения: 1 <= 𝑁 <= 5 · 10^4, 0 <= 𝑀 <= 5 · 10^4. </br>
**Формат выходных данных** </br>
𝑀 ответов на запросы.

## Test5

### Task3

**Условие** </br>
Двудольным графом называется граф (𝑉, 𝐸), 𝐸 ⊂ 𝑉 × 𝑉 такой, что его множество вершин
𝑉 можно разбить на два подмножества 𝐴 и 𝐵, для которых ∀(𝑒1, 𝑒2) ∈ 𝐸 𝑒1 ∈ 𝐴, 𝑒2 ∈ 𝐵 и
𝐴, 𝐵 ⊂ 𝐸, 𝐴 ∩ 𝐵 = ∅.
Паросочетанием в двудольном графе называется любой его набор несмежных ребер, то
есть такой набор 𝑆 ⊂ 𝐸, что для любых двух ребер 𝑒1 = (𝑢1, 𝑣1), 𝑒2 = (𝑢2, 𝑣2) из 𝑆 выполнено
𝑢1 ̸ = 𝑢2 и 𝑣1 ̸ = 𝑣2.
Ваша задача — найти максимальное паросочтание в двудольном графе, то есть паросо-
четание с максимально возможным числом ребер. </br>
**Формат входных данных** </br>
В первой строке записаны два целых числа 𝑛 и 𝑚 (1 ≤ 𝑛, 𝑚 6 250) — число вершин в 𝐴
и число вершин в 𝐵.
Далее следуют 𝑛 строк с описаниями ребер. 𝑖-я вершина из 𝐴 описана в 𝑖 + 1-й строке
файла. Каждая из этих строк содержит номера вершин из 𝐵, соединенных с 𝑖-й вершиной
𝐴. Вершины в 𝐴 и 𝐵 нумеруются независимо (с единицы). Список завершается числом 0. </br>
**Формат выходных данных** </br>
Первая строка выходного файла должна содержать одно целое число 𝑙 — количество
ребер в максимальном паросочетании. Далее должны следовать 𝑙 строк, в каждой из которых
должны быть два целых числа 𝑢𝑗 и 𝑣𝑗 — концы ребер паросочетания в 𝐴 и 𝐵, соотвественно.
