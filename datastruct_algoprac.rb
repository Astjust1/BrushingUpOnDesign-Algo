def factorial(n)
  if n == 0 then return 1 end
  return n * factorial(n-1)
end

#puts factorial(52) runtime is Tbase_case + n(TRecursion)
=begin Extending the array class to record a base index and not
allow negetive indecies like it does normally
=end
class Array
  alias_method :init, :initialize
  alias_method :getitem, :[]
  alias_method :setitem, :[]=

  protected :getitem , :setitem

  def initialize(size =0, baseIndex=0)
    init(size,nil) #using nil here clears array values of garbage
    @baseIndex = baseIndex
  end

  def getOffset(index)
    @baseIndex = 0 if @baseIndex.nil?
    raise IndexError if not \
      (@baseIndex ... @baseIndex + length) === index
    return index - @baseIndex
  end
end
