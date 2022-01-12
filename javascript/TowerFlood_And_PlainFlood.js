//City Swim - 2D (TowerFlood And PlainFlood)
/*
Given an array representing the height of towers on a 2d plane, with each tower being of width 1, Whats's the maximum amount of units of water that can be captured between the towers when it rains?

Each tower is immediately next to the tower next to it in the array, except in instances where a height of 0 is shown, then no tower would be present.

A single unit can be thought of as a 2d square with a width 1.
Examples

          [5,2,10] should return 3
  [1,0,5,2,6,3,10] should return 7
[15,0,6,10,11,2,5] should return 20
           [1,5,1] should return 0
             [6,5] should return 0
                [] should return 0

Performances:

Watch out for performances: you'll need a solution linear with the number of towers.
*/



function rainVolume(towers) {
    let leftMax = [];
    leftMax.push(0);
    let rightMax = [];
    rightMax.push(0);
    let length = towers.length - 1;
    for (let i = 0; i < towers.length; i++) {
        if (towers[i] > leftMax[leftMax.length - 1]) {
            leftMax.push(towers[i]);
        }else {
            leftMax.push(leftMax[leftMax.length-1])
        }
        if (towers[length -i] > rightMax[rightMax.length - 1]) {
            rightMax.push(towers[length-i]);
        } else {
            rightMax.push(rightMax[rightMax.length-1]);
        }
    }
    let ans = 0;
    for(let i = 0; i <= length;i++) {
        let temp = Math.min(leftMax[i],rightMax[rightMax.length-1-i]);
        temp = temp-towers[i];
        if(temp>0)
        ans += temp;
    }
    console.log(leftMax,rightMax);
    return ans;
}


console.log(rainVolume([5, 2, 10]));
console.log(rainVolume([1,0,5,2,6,3,10]));
console.log(rainVolume([15,0,6,10,11,2,5]))