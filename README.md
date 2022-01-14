# Simplest-cpp-plot
Simplest method to build line plot (or other graphics, by modifiing basic functions) in console.

Setting window size:
```c++
	window();
```
Write points to console:
```c++
	for (int j = 12; j > 1; j--)
	{
		print "\n\n";
		print j;
	}
	print endl;
	for (int j = 5; j <= 20; j += 5)
	{
		print "                  ";
		print j;
	}
```
Draw lines:
```c++
	plot(12, 20, x, y1, "pink");

	plot(12, 20, x, y2, "lime");

	plot(12, 20, x, y3, "violet");

	plot(12, 20, x, y4, "orange");
```
Result:
![result](result.png)
