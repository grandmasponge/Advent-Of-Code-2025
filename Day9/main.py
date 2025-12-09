import math
filename = "input.txt"
inputs = [(int(x), int(y)) for line in open("input.txt") for x, y in [line.strip().split(",")]]

def ray_cast(point, polygon): #stack overflow :3
    x, y = point
    
    for k in range(len(polygon)):
        next_k = (k + 1) % len(polygon)
        x1, y1 = polygon[k]
        x2, y2 = polygon[next_k]
        
       
        if x1 == x2:  
            if x == x1 and min(y1, y2) <= y <= max(y1, y2):
                return True
        elif y1 == y2:  
            if y == y1 and min(x1, x2) <= x <= max(x1, x2):
                return True
        else:  
       
            cross = (y - y1) * (x2 - x1) - (x - x1) * (y2 - y1)
            if abs(cross) < 1e-9:  
                if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
                    return True
    

    intersections = 0
    for k in range(len(polygon)):
        next_k = (k + 1) % len(polygon)
        x1, y1 = polygon[k]
        x2, y2 = polygon[next_k]
        if (y < y1) != (y < y2) and x < (x2-x1) * (y-y1)/(y2-y1) + x1:
            intersections += 1
    return intersections % 2 == 1


largest_area = 0
n = len(inputs)

for i in range(n):
    x1, y1 = inputs[i]
    for j in range(i + 1, n):
        x2, y2 = inputs[j]
        
        
        if x1 == x2 or y1 == y2:
            continue
        
    
        min_x = min(x1, x2)
        max_x = max(x1, x2)
        min_y = min(y1, y2)
        max_y = max(y1, y2)
        
        
        corners = [
            (min_x, min_y),
            (min_x, max_y),
            (max_x, min_y),
            (max_x, max_y)
        ]
        
    
        all_inside = True
        for corner in corners:
            if not ray_cast(corner, inputs):
                all_inside = False
                break
        
      
        if not all_inside:
            continue
        
    
        dx = max_x - min_x + 1
        dy = max_y - min_y + 1
        area = dx * dy
        
        if area > largest_area:
            largest_area = area
            print(largest_area)

print(largest_area)