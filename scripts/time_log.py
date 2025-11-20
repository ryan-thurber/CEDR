import matplotlib.pyplot as plt
import sys

times = []
threads = []
init_time = None

with open(sys.argv[1],'r') as logfile:
    for line in logfile:
        fields = line.split()
        if not init_time:
            init_time = int(fields[3])
        new_time = (int(fields[3])-init_time)/1000000
        print(f"{new_time} on thread {fields[5]}")
        times.append(new_time)
        threads.append(fields[5])


fig, ax = plt.subplots()

ax.scatter(times,threads)

ax.set_xlabel('Time (ms)')
ax.set_ylabel('Thread ID')
# ax.set_title('Numerical X-axis, String Y-axis Example')

plt.show()

