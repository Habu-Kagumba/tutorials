#!/usr/bin/env ruby
# encoding: UTF-8

require 'faker'

module Filter
  module ClassMethods
  end

  def self.included(receiver)
    receiver.extend         ClassMethods
  end
end

class Product
  include Filter
  attr_reader :item

  @@all = []
  @@result = []

  Product = Struct.new(:price, :rating, :color, :sales)

  def initialize(item={})
    @item = Product.new(
      item[:price],
      item[:rating],
      item[:color],
      item[:sales]
    )
  end

  def self.all
    @@all.map(&:item)
  end

  def self.sample
    @@all.sample.item
  end

  def self.filter(attribute, operation, datum)
    @@result = @@all.select do |product|
      product[attribute].send(operation, datum)
    end
    self
  end

  def self.result
    @@result
  end

  def destroy_all
    @@all.clear
  end

  def save
    @@all << self
    self
  end

  def add(product)
    self.class.new(product).save
  end
end
