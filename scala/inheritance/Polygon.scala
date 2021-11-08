package inheritance

class Polygon{
  def area :Double = 0.0
}

object Polygon{
  def main(args:Array[String])={
    var poly = new Polygon
    var rect = new Rectangle(2,7)
    var tri = new Triangle(2,3)
    printArea(tri)
  }

  def printArea(p:Polygon)={
    println(p.area)
  }
}