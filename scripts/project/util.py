class TimeStamp():
    dev_type="cpu"
    queue_time = None
    run_time = None
    thread_id = None

#TODO update when other accels are mocked
def read_logfile(filename):
    ts = []
    init_time = None
    with open(filename,'r') as logfile:
        for line in logfile:
            fields = line.split()
            if not init_time:
                init_time = int(fields[1])
            queue_time = (int(fields[1])-init_time)/1000000
            run_time = (int(fields[3])-init_time)/1000000
            #print(f"{new_time} on thread {fields[5]}")
            new_ts = TimeStamp()
            new_ts.queue_time = queue_time
            new_ts.run_time = run_time
            new_ts.thread_id = fields[5]
            ts.append(new_ts)
    return ts