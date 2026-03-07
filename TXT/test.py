target = 100
position = [0,2,4]
speed = [4,2,1]

def carFleet(target: int, position: list[int], speed: list[int]) -> int:
	stack = []
	
	times = sorted(zip(position, speed))
	
	for i in range(len(times) - 1, -1, -1):
		p, s = times[i]
		time = (target - p) / s
		
		stack.append(time)
		while len(stack) > 1 and stack[-1] <= stack[-2]:
			stack.pop()
		
		
	return len(stack)

res = carFleet(target, position, speed)
print(res)