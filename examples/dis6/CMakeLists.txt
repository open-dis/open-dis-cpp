target_sources(ExampleSender
  PRIVATE
  "main.cpp"
  "Utils.cpp"
)

target_sources(ExampleReceiver
  PRIVATE
  "main_receive.cpp"
  "Utils.cpp"
  "EntityStatePduProcessor.cpp"
)
