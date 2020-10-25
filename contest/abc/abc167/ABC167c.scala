package abc167

import java.io.PrintWriter
import java.util.Scanner

object Main extends App {
  val pw = new PrintWriter(System.out)
  val sc = new Scanner(System.in)

  val n, m, x = sc.nextInt()
  val aArr = new Array[Array[Int]](n)
  val cArr = new Array[Int](n)

  (0 until n).foreach { i =>
    cArr(i) = sc.nextInt()
    aArr(i) = (0 until m).map(_ => sc.nextInt()).toArray
  }
  val default = 1e9.toInt

  def dfs(idx: Int, sum: Int, willBuy: Boolean, skills: Array[Int]): Int = {
    if (idx > n - 1) {
      if (!skills.exists(_ < x)) sum
      else default
    } else {
      if (willBuy) {
        val nxt = aArr(idx).zip(skills).map { case (a, skill) => a + skill }
        val nxtSum = sum + cArr(idx)
        dfs(idx + 1, nxtSum, willBuy = true, nxt) min dfs(idx + 1, nxtSum, willBuy = false, nxt)
      } else {
        dfs(idx + 1, sum, willBuy = true, skills) min dfs(idx + 1, sum, willBuy = false, skills)
      }
    }
  }

  val result = dfs(-1, 0, willBuy = false, new Array[Int](m))
  val ans = if (result == default) -1 else result
  pw.println(ans)
  pw.flush()
}
