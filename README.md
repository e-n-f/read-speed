read-speed
==========

How fast can you read data from different types of media?

So far:

       2 MB/sec: ssh over WiFi (Mac to Linux)
      31 MB/sec: USB 2.0 (Seagate 4TB Backup+, Linux)
      73 MB/sec: ssh over gigabit Ethernet (Mac Thunderbolt to Linux)
     129 MB/sec: USB 3.0 (Seagate 4TB Extra Storage, Linux)
     163 MB/sec: SATA (Seagate internal 1TB, Linux)
     260 MB/sec: Storm on Demand SSD (Linux)
     485 MB/sec: MacBook Air SSD
    5600 MB/sec: Linux buffer cache (4400 MB/sec if accessed less recently?)

By MB I mean 1048576 bytes, not 1000000.
