import sys
from util import read_logfile

# Number of uninterrupted schedules we expect to get a good average
# Assume we run on all accels once uninteruppeted
STARTUP_COST = 3

ts_list= read_logfile(sys.argv[1])

devices = []

last_ts = None
running_sum = 0
running_sum_index = 0
running_average = 0
last_device = None

for i,ts in enumerate(ts_list):
    # Keep ordered list of devices in RR scheduler
    if ts.thread_id not in devices:
        devices.append(ts.thread_id)
    device_num = devices.index(ts.thread_id)
    passed_time = ts.run_time - ts.queue_time
    if i < STARTUP_COST:
        running_sum += passed_time
        running_sum_index += 1
    else:
        running_average = running_sum / running_sum_index
        order_detection = False
        if last_ts.thread_id != devices[device_num-1]:
            order_detection = True
        # check for detection
        timing_detection = False
        delta = abs((passed_time - running_average)/running_average)
        print(f"After attack #{i} running avg = {running_average} passed_time = {passed_time} delta = {delta}")
        if abs((passed_time - running_average)/running_average) > 1:
            timing_detection = True
        if not timing_detection:
            running_sum += passed_time
            running_sum_index += 1
        if order_detection and timing_detection:
            # Works because 0 index i is call i-1
            print(f"Full detection after attacker call #{i}")
        elif order_detection:
            print(f"Order detection after attacker call #{i}")
        elif timing_detection:
            print(f"Timing detection after attacker call #{i}")

    last_ts = ts