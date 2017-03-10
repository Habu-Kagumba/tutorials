#!/usr/bin/env ruby
# encoding: UTF-8
require 'ox'

module RXT
  class DSL
    attr_reader :__root

    def initialize
      @__root = Ox::Document.new
      @__element_stack = [@__root]
    end

    def xml(attrs={})
      attrs.each do |key, value|
        @__root[key] = value
      end
    end

    def respond_to_missing?(method_name, include_private=false)
      true # respond to all methods
    end

    def method_missing(method_name, *args)
      elem = __make_element(method_name, *args)
      @__element_stack.last << elem
      @__element_stack.push(elem)

      yield if block_given?

      @__element_stack.pop
    end

    def __make_element(name, attributes_or_content={}, content=nil)
      if attributes_or_content.is_a?(Hash)
        attributes = attributes_or_content
      else
        attributes = {}
        content = attributes_or_content
      end

      Ox::Element.new(name.to_s).tap do |elem|
        attributes.each { |key, value| elem[key] = value }
        elem << content.to_s unless content.nil?
      end
    end
  end
end
