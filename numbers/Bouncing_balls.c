int bouncingBall(double h, double bounce, double window)
{
    if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)
        return -1;
    double bounceheight = h * bounce;
    int count = 1;
    while (bounceheight > window)
    {
        count += 2;
        bounceheight = bounceheight * bounce;
    }
    return count;
}