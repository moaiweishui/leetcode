import util.control.Breaks._
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        var left = 0
        var right = 0
        var map = new scala.collection.mutable.HashMap[Int, Int]()
        breakable(
            for(i <- nums.indices){
                val x = target - nums(i)
                if(map.contains(x)){
                    left = map(x)
                    right = i
                    break()
                }
                map += (nums(i) -> i)
            }
        )
        Array(left, right)
    }
}
