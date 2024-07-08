import matplotlib.pyplot as plt

# Data
orders = ['Random Order', 'Half Random', 'Ascending Order']
list_sort = [721306, 579353, 437120]
timsort = [770839, 451795, 105515]
pdqsort = [954597, 670515, 100008]

# Plotting
plt.figure(figsize=(10, 6))

plt.plot(orders, list_sort, marker='o', label='list_sort', color="orange")
plt.plot(orders, timsort, marker='o', label='Timsort', color="royalblue")
plt.plot(orders, pdqsort, marker='o', label='pdqsort', color="darkviolet")

# plt.title('Sorting Algorithms Performance')
# plt.xlabel('Order of Data')
plt.ylabel('Number of comparisons')
plt.legend()
plt.grid(True)
plt.show()

