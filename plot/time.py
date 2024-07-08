import matplotlib.pyplot as plt

# Data
orders = ['Random Order', 'Half Random', 'Ascending Order']
list_sort = [0.011339, 0.007334, 0.003127]
timsort = [0.010800, 0.006555, 0.001418]
pdqsort = [0.009194, 0.006200, 0.000532]

# Plotting
plt.figure(figsize=(10, 6))

plt.plot(orders, list_sort, marker='o', label='list_sort', color="orange")
plt.plot(orders, timsort, marker='o', label='Timsort', color="royalblue")
plt.plot(orders, pdqsort, marker='o', label='pdqsort', color="darkviolet")

plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)
plt.show()

