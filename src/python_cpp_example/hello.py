import python_cpp_example

def say_hello():
    print("Hello world!")

print(python_cpp_example.add(1, 2))
python_cpp_example.average(1,5)

from python_cpp_example import Pet

my_dog = Pet('Pluto', 5)
print(my_dog.get_hunger())
my_dog.go_for_a_walk()
print(my_dog.get_hunger())

from python_cpp_example import Accumulator
from python_cpp_example import CovarianceAccumulator

my_accumulator = Accumulator(1, 2, 3, 4)

my_accumulator.append(1, 5)
my_accumulator.append(2, 3)
my_accumulator.append(3, 1) # 0.49 * 0.5 + 0.09 * 0.3 + 1.69 * 0.2 = 0.25 + 0.027 + 0.34 = 0.69

# print(my_accumulator.get_mean())
# print(my_accumulator.get_variance())
# my_accumulator.reset()
# print(my_accumulator.get_mean())
# print(my_accumulator.get_variance())

my_accumulator = CovarianceAccumulator(1, 2, 3, 4)

my_accumulator.append(1, 1, 3)
my_accumulator.append(2, 1, 2)
my_accumulator.append(3, 1, 1) # 0.49 * 0.5 + 0.09 * 0.3 + 1.69 * 0.2 = 0.25 + 0.027 + 0.34 = 0.69
print(my_accumulator.get_covariance())
