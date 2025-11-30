import matplotlib.pyplot as plt
import sys
from util import read_logfile

ts = read_logfile(sys.argv[1])

fig, ax = plt.subplots()

times = [x.run_time for x in ts]
threads = [x.thread_id for x in ts]

ax.scatter(times,threads)

ax.set_xlabel('Time (ms)')
ax.set_ylabel('Thread ID')
ax.set_title('Run times of attacker Application')

plt.show()

