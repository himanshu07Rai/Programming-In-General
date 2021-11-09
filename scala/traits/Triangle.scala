package inheritance



class Triangle(b:Int,h:Int) extends Polygon{
  override def area:Double = b*h/2
}

object Triangle{
  def main(args:Array[String]):Unit={
    println("yo")
  }
}

