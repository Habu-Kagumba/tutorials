#!/usr/bin/env ruby
# encoding: UTF-8
prices = [100, 75, 90, 80, 50]

proc_discount = Proc.new do |price|
  price - (price * 0.15)
end

proc_tax = Proc.new do |price|
  price + (price * 0.2)
end

p prices.map(&proc_discount)
p prices.map(&proc_tax)

lambda_discount = -> price do
  price - (price * 0.15)
end

lambda_tax = -> price do
  price + (price * 0.2)
end

p prices.map(&lambda_discount)
p prices.map(&lambda_tax)

def map_words(input)
  results = []
  input.split.each do |word|
    results << yield(word)
  end
  results
end

p map_words("Name is Herbert") { |word| word.size }
