def solution(n, t, m, timetable):
    crew = []
    for time in timetable:
        h, mi = map(int, time.split(":"))
        crew.append(h * 60 + mi)
    
    crew.sort()
    idx = 0
    start = 9 * 60
    
    for bus in range(n):
        bus_time = start + bus * t
        count = 0
        
        while idx < len(crew) and crew[idx] <= bus_time and count < m:
            idx += 1
            count += 1
        
        if bus == n - 1:
            if count < m:
                answer = bus_time
            else:
                answer = crew[idx - 1] - 1
    
    hh = answer // 60
    mm = answer % 60
    return f"{hh:02d}:{mm:02d}"