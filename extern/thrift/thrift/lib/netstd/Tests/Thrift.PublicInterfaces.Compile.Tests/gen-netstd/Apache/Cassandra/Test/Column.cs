/**
 * Autogenerated by Thrift Compiler (0.14.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.Extensions.Logging;
using Thrift;
using Thrift.Collections;
using System.ServiceModel;
using System.Runtime.Serialization;

using Thrift.Protocol;
using Thrift.Protocol.Entities;
using Thrift.Protocol.Utilities;
using Thrift.Transport;
using Thrift.Transport.Client;
using Thrift.Transport.Server;
using Thrift.Processor;


#pragma warning disable IDE0079  // remove unnecessary pragmas
#pragma warning disable IDE1006  // parts of the code use IDL spelling

namespace Apache.Cassandra.Test
{

  /// <summary>
  /// Basic unit of data within a ColumnFamily.
  /// @param name, the name by which this column is set and retrieved.  Maximum 64KB long.
  /// @param value. The data associated with the name.  Maximum 2GB long, but in practice you should limit it to small numbers of MB (since Thrift must read the full value into memory to operate on it).
  /// @param timestamp. The timestamp is used for conflict detection/resolution when two columns with same name need to be compared.
  /// @param ttl. An optional, positive delay (in seconds) after which the column will be automatically deleted.
  /// </summary>
  [DataContract(Namespace="")]
  public partial class Column : TBase
  {
    private byte[] _value;
    private long _timestamp;
    private int _ttl;

    [DataMember(Order = 0)]
    public byte[] Name { get; set; }

    [DataMember(Order = 0)]
    public byte[] Value
    {
      get
      {
        return _value;
      }
      set
      {
        __isset.@value = true;
        this._value = value;
      }
    }

    [DataMember(Order = 0)]
    public long Timestamp
    {
      get
      {
        return _timestamp;
      }
      set
      {
        __isset.timestamp = true;
        this._timestamp = value;
      }
    }

    [DataMember(Order = 0)]
    public int Ttl
    {
      get
      {
        return _ttl;
      }
      set
      {
        __isset.ttl = true;
        this._ttl = value;
      }
    }


    [DataMember(Order = 1)]
    public Isset __isset;
    [DataContract]
    public struct Isset
    {
      [DataMember]
      public bool @value;
      [DataMember]
      public bool timestamp;
      [DataMember]
      public bool ttl;
    }

    #region XmlSerializer support

    public bool ShouldSerializeValue()
    {
      return __isset.@value;
    }

    public bool ShouldSerializeTimestamp()
    {
      return __isset.timestamp;
    }

    public bool ShouldSerializeTtl()
    {
      return __isset.ttl;
    }

    #endregion XmlSerializer support

    public Column()
    {
    }

    public Column(byte[] name) : this()
    {
      this.Name = name;
    }

    public Column DeepCopy()
    {
      var tmp0 = new Column();
      if((Name != null))
      {
        tmp0.Name = this.Name.ToArray();
      }
      if((Value != null) && __isset.@value)
      {
        tmp0.Value = this.Value.ToArray();
      }
      tmp0.__isset.@value = this.__isset.@value;
      if(__isset.timestamp)
      {
        tmp0.Timestamp = this.Timestamp;
      }
      tmp0.__isset.timestamp = this.__isset.timestamp;
      if(__isset.ttl)
      {
        tmp0.Ttl = this.Ttl;
      }
      tmp0.__isset.ttl = this.__isset.ttl;
      return tmp0;
    }

    public async global::System.Threading.Tasks.Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        bool isset_name = false;
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.String)
              {
                Name = await iprot.ReadBinaryAsync(cancellationToken);
                isset_name = true;
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case 2:
              if (field.Type == TType.String)
              {
                Value = await iprot.ReadBinaryAsync(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case 3:
              if (field.Type == TType.I64)
              {
                Timestamp = await iprot.ReadI64Async(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case 4:
              if (field.Type == TType.I32)
              {
                Ttl = await iprot.ReadI32Async(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
        if (!isset_name)
        {
          throw new TProtocolException(TProtocolException.INVALID_DATA);
        }
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async global::System.Threading.Tasks.Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("Column");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();
        if((Name != null))
        {
          field.Name = "name";
          field.Type = TType.String;
          field.ID = 1;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteBinaryAsync(Name, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        if((Value != null) && __isset.@value)
        {
          field.Name = "value";
          field.Type = TType.String;
          field.ID = 2;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteBinaryAsync(Value, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        if(__isset.timestamp)
        {
          field.Name = "timestamp";
          field.Type = TType.I64;
          field.ID = 3;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteI64Async(Timestamp, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        if(__isset.ttl)
        {
          field.Name = "ttl";
          field.Type = TType.I32;
          field.ID = 4;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteI32Async(Ttl, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      if (!(that is Column other)) return false;
      if (ReferenceEquals(this, other)) return true;
      return TCollections.Equals(Name, other.Name)
        && ((__isset.@value == other.__isset.@value) && ((!__isset.@value) || (TCollections.Equals(Value, other.Value))))
        && ((__isset.timestamp == other.__isset.timestamp) && ((!__isset.timestamp) || (System.Object.Equals(Timestamp, other.Timestamp))))
        && ((__isset.ttl == other.__isset.ttl) && ((!__isset.ttl) || (System.Object.Equals(Ttl, other.Ttl))));
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if((Name != null))
        {
          hashcode = (hashcode * 397) + Name.GetHashCode();
        }
        if((Value != null) && __isset.@value)
        {
          hashcode = (hashcode * 397) + Value.GetHashCode();
        }
        if(__isset.timestamp)
        {
          hashcode = (hashcode * 397) + Timestamp.GetHashCode();
        }
        if(__isset.ttl)
        {
          hashcode = (hashcode * 397) + Ttl.GetHashCode();
        }
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("Column(");
      if((Name != null))
      {
        sb.Append(", Name: ");
        Name.ToString(sb);
      }
      if((Value != null) && __isset.@value)
      {
        sb.Append(", Value: ");
        Value.ToString(sb);
      }
      if(__isset.timestamp)
      {
        sb.Append(", Timestamp: ");
        Timestamp.ToString(sb);
      }
      if(__isset.ttl)
      {
        sb.Append(", Ttl: ");
        Ttl.ToString(sb);
      }
      sb.Append(')');
      return sb.ToString();
    }
  }

}