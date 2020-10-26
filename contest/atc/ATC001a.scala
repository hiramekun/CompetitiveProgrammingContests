import java.io.PrintWriter
import java.util.Scanner

object Main extends App {
  val pw = new PrintWriter(System.out)
  val sc = new Scanner(System.in)

  val h, w = sc.nextInt()
  val c = Array.fill(h)(sc.next())
  val seen = Array.ofDim[Boolean](h, w)
  val s = for {
    i <- 0 until h
    j <- 0 until w
    if c(i)(j) == 's'
  } yield (i, j)

  val dis = Array(1, 0, -1, 0)
  val djs = Array(0, 1, 0, -1)

  def dfs(i: Int, j: Int): Boolean = {
    var ret = false
    (0 until 4).foreach { idx =>
      val ni = i + dis(idx)
      val nj = j + djs(idx)
      if (0 <= ni && ni <= h - 1 && 0 <= nj && nj <= w - 1 && !seen(ni)(nj)) {
        seen(ni)(nj) = true
        if (c(ni)(nj) == '.') ret = ret || dfs(ni, nj)
        else if (c(ni)(nj) == 'g') ret = true
      }
    }
    ret
  }

  val (si, sj) = s.head
  seen(si)(sj) = true
  val ans = if (dfs(si, sj)) "Yes" else "No"
  pw.println(ans)
  pw.flush()
}
