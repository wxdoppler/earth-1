require 'thread'
require 'snapshot'

FileAdded = Struct.new(:filename)
FileRemoved = Struct.new(:filename)

class Monitor
  attr_reader :queue
  
  def initialize(directory)
    @snapshot = Snapshot.new(directory)
  end
  
  def exist?(path)
    @snapshot.exist?(path)
  end
  
  def file_added(name)
    puts "File #{name} added"
  end
  
  def file_removed(name)
    puts "File #{name} removed"
  end
  
  def update
    old_snapshot = @snapshot.deep_copy
    @snapshot.update
    Snapshot.added_files(old_snapshot, @snapshot).each {|x| file_added(x)}
    Snapshot.removed_files(old_snapshot, @snapshot).each {|x| file_removed(x)}
  end
end

class MonitorWithQueue < Monitor
  def initialize(directory)
    super(directory)
    @queue = Queue.new    
  end
  
  def file_added(name)
    @queue.push(FileAdded.new(name))
  end
  
  def file_removed(name)
    @queue.push(FileRemoved.new(name))
  end
  
end

