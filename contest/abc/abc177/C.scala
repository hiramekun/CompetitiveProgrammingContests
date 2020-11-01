package abc177

import scala.io.StdIn

object Main extends App {
  val n = StdIn.readInt()
  val a = StdIn.readLine().split(" ").map(_.toLong)

  val mod = 1e9.toLong + 7
  val d = a.scanLeft(0L)((acc, v) => (acc + v) % mod)
  val ans = a.zipWithIndex.foldLeft(0L) { (acc, vi) =>
    var diff = d.last - d(vi._2 + 1)
    if (diff < 0) diff += mod
    diff %= mod
    (acc + (diff * vi._1) % mod) % mod
  }
  println(ans)
}
