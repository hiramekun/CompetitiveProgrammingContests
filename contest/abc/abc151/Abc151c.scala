object Main extends App {
  val pw = new java.io.PrintWriter(System.out)
  val sc = new java.util.Scanner(System.in)

  val n, m = sc.nextInt
  val aced = Array.ofDim[Boolean](n + 1)
  val penalty = Array.ofDim[Int](n + 1)

  (1 to m).foreach { _ =>
    val p = sc.nextInt
    val s = sc.next
    if (s == "AC") aced(p) = true
    else if (!aced(p)) penalty(p) = penalty(p) + 1
  }
  val (ac, wa) = aced.zip(penalty).foldRight((0, 0)) {
    case ((aced, penalty), (accAc, accPen)) =>
      if (aced) (accAc + 1, accPen + penalty)
      else (accAc, accPen)
  }

  pw.println(s"$ac $wa")
  pw.flush()
}
