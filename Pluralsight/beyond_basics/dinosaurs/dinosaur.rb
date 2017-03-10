require './lib/seed'

class Dinosaur
  def self.add_attribute(name, value)
    define_method(name) do
      value
    end
  end

  def self.match_on(*attr_name, &block)
    attr_name.each do |attr|
      method_name = "match_#{attr}"
      matcher = block || -> (attribute, value) { attribute == value }
      define_method(method_name) do |value|
        attr = self.send(attr)
        matcher.call(attr, value)
      end
    end
  end

  def initialize(data)
    data.each do |key, value|
      self.class.add_attribute(key, value)
    end
  end
end
