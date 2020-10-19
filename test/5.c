semaphore full1 = 0,full2 = 0;//司机和售票员
semaphore door1 = 1,door2 = 1;//门
void driver()
{
	while(true)
	{
		wait(door1);// 有售票员关门后司机才能开车
		wait(door2);
		// 开车;
		// 行车;
		// 停车;
		signal(full1);//停车开门
		signal(full2);
	}
}
void seller1()
{
	while(true)
	{
		wait(full1);//停车开门
		// 开门
		// 关门
		signal(door1);
		// 售票
	}
}
void seller2()
{
	while(true)
	{
		wait(full2);//停车开门
		// 开门
		// 关门
		signal(door2);
		// 售票
	}
}
