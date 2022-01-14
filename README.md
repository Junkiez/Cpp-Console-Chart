# Simplest-cpp-plot
Simplest method to build line plot (or other graphics, by modifiing basic functions) in console.

```c++
	window();
```
Setting window size
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
Write points to console
```c++
	plot(12, 20, x, y1, "pink");

	plot(12, 20, x, y2, "lime");

	plot(12, 20, x, y3, "violet");

	plot(12, 20, x, y4, "orange");
```
Draw lines
![result](result.png)
