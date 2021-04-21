target_sources(dis7_ExampleSender
  PRIVATE
  "main.cpp"
  "Utils.cpp"
)

target_sources(dis7_ExampleReceiver
  PRIVATE
  "main_receive.cpp"
  "Utils.cpp"
  "EntityStatePduProcessor.cpp"
)
